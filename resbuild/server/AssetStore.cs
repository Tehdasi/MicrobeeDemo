using System.Globalization;
using Microsoft.Data.Sqlite;

namespace Resbuild.Server;

/// <summary>
/// The asset database, <c>resbuild.db</c>. Every write commits straight away, so the page can save
/// as the user edits. Older databases are upgraded when opened: v1 (from before images) gains the
/// images table, and v2 (the font called e22_font) has its rows renamed to wavetext_font.
/// </summary>
public sealed class AssetStore : IDisposable
{
    public const string FileName = "resbuild.db";
    private const int SchemaVersion = 3;

    /// <summary>What wavetext_font was called up to schema v2.</summary>
    private const string RenamedFontType = "e22_font";

    private const string ImagesTable = """
        CREATE TABLE images (
            id         INTEGER PRIMARY KEY AUTOINCREMENT,
            asset_type TEXT    NOT NULL,
            name       TEXT    NOT NULL,
            position   INTEGER NOT NULL,
            width      INTEGER NOT NULL,
            height     INTEGER NOT NULL,
            pixels     BLOB    NOT NULL,
            updated_at TEXT    NOT NULL
        );
        CREATE UNIQUE INDEX images_name ON images (name COLLATE NOCASE);
        """;

    private readonly SqliteConnection _db;
    private readonly Lock _gate = new();

    public AssetStore(string directory)
    {
        var fullDirectory = Path.GetFullPath(directory);
        Directory.CreateDirectory(fullDirectory);
        DatabasePath = Path.Combine(fullDirectory, FileName);

        _db = new SqliteConnection(new SqliteConnectionStringBuilder
        {
            DataSource = DatabasePath,
            Mode = SqliteOpenMode.ReadWriteCreate,
            Pooling = false,
        }.ToString());
        _db.Open();
        Execute(null, "PRAGMA journal_mode = WAL; PRAGMA synchronous = NORMAL;");
        EnsureSchema();
    }

    public string DatabasePath { get; }

    public void Dispose()
    {
        lock (_gate) _db.Dispose();
    }

    // ------------------------------------------------------------------ font

    public FontData GetFont()
    {
        lock (_gate)
        {
            var text = Scalar(null, "SELECT value FROM strings WHERE asset_type = $type AND item = $item;",
                ("$type", WavetextFont.AssetType), ("$item", WavetextFont.TextItem)) as string ?? "";

            var tiles = new Dictionary<int, byte[]>();
            using var command = Command(null, """
                SELECT code, rows FROM tiles
                WHERE asset_type = $type AND item = $item AND code BETWEEN $first AND $last;
                """,
                ("$type", WavetextFont.AssetType), ("$item", WavetextFont.TilesItem),
                ("$first", WavetextFont.FirstCode), ("$last", WavetextFont.LastCode));
            using var reader = command.ExecuteReader();
            while (reader.Read())
            {
                var stored = (byte[])reader.GetValue(1);
                var rows = new byte[WavetextFont.TileHeight];
                Array.Copy(stored, rows, Math.Min(stored.Length, rows.Length));
                if (rows.Any(row => row != 0)) tiles[reader.GetInt32(0)] = rows;
            }
            return new FontData(text, tiles);
        }
    }

    public string SetText(string? text)
    {
        if (text is null) throw new InvalidInputException("The string is missing (it can be empty).");
        if (text.Length > WavetextFont.MaxTextLength)
            throw new InvalidInputException($"The string can be at most {WavetextFont.MaxTextLength} characters.");
        foreach (var character in text)
        {
            if (character is < (char)WavetextFont.FirstCode or > (char)WavetextFont.LastCode)
                throw new InvalidInputException(
                    $"The string cannot hold U+{(int)character:X4}: only printable ASCII ({WavetextFont.FirstCode}-{WavetextFont.LastCode}).");
        }

        lock (_gate)
        {
            Execute(null, """
                INSERT INTO strings (asset_type, item, value, updated_at) VALUES ($type, $item, $value, $now)
                ON CONFLICT (asset_type, item) DO UPDATE SET value = excluded.value, updated_at = excluded.updated_at;
                """,
                ("$type", WavetextFont.AssetType), ("$item", WavetextFont.TextItem), ("$value", text), ("$now", Now()));
        }
        return text;
    }

    public void SetTiles(IReadOnlyDictionary<int, int[]?> tiles)
    {
        // Check the whole batch first, so a bad tile leaves nothing half written.
        var writes = new List<(int Code, byte[]? Rows)>();
        foreach (var (code, rows) in tiles)
        {
            if (code is < WavetextFont.FirstCode or > WavetextFont.LastCode)
                throw new InvalidInputException($"There is no tile for character {code}: tiles cover {WavetextFont.FirstCode}-{WavetextFont.LastCode}.");
            if (rows is null || rows.Length != WavetextFont.TileHeight)
                throw new InvalidInputException($"Tile {code} needs {WavetextFont.TileHeight} rows.");
            if (rows.Any(row => row is < 0 or > 0xff))
                throw new InvalidInputException($"Tile {code} has a row that does not fit in 8 pixels.");
            var bytes = rows.Select(row => (byte)row).ToArray();
            writes.Add((code, bytes.Any(row => row != 0) ? bytes : null));
        }

        lock (_gate)
        {
            using var tx = _db.BeginTransaction();
            var now = Now();
            foreach (var (code, rows) in writes)
            {
                if (rows is null)
                {
                    Execute(tx, "DELETE FROM tiles WHERE asset_type = $type AND item = $item AND code = $code;",
                        ("$type", WavetextFont.AssetType), ("$item", WavetextFont.TilesItem), ("$code", code));
                }
                else
                {
                    Execute(tx, """
                        INSERT INTO tiles (asset_type, item, code, rows, updated_at) VALUES ($type, $item, $code, $rows, $now)
                        ON CONFLICT (asset_type, item, code) DO UPDATE SET rows = excluded.rows, updated_at = excluded.updated_at;
                        """,
                        ("$type", WavetextFont.AssetType), ("$item", WavetextFont.TilesItem), ("$code", code), ("$rows", rows), ("$now", now));
                }
            }
            tx.Commit();
        }
    }

    // ---------------------------------------------------------------- images

    public List<ImageData> GetImages()
    {
        lock (_gate)
        {
            using var command = Command(null,
                "SELECT id, name, width, height, pixels FROM images WHERE asset_type = $type ORDER BY position, id;",
                ("$type", Evlores.AssetType));
            using var reader = command.ExecuteReader();
            var images = new List<ImageData>();
            while (reader.Read()) images.Add(ReadImage(reader));
            return images;
        }
    }

    public ImageData? GetImage(long id)
    {
        lock (_gate)
        {
            using var command = Command(null,
                "SELECT id, name, width, height, pixels FROM images WHERE id = $id AND asset_type = $type;",
                ("$id", id), ("$type", Evlores.AssetType));
            using var reader = command.ExecuteReader();
            return reader.Read() ? ReadImage(reader) : null;
        }
    }

    /// <summary>A new image, every pixel colour 0, after the others.</summary>
    public ImageData CreateImage(string? name, int? width, int? height)
    {
        var cleanWidth = width ?? Evlores.DefaultWidth;
        var cleanHeight = height ?? Evlores.DefaultHeight;
        CheckSize(cleanWidth, cleanHeight);
        var pixels = new byte[cleanWidth * cleanHeight];

        lock (_gate)
        {
            using var tx = _db.BeginTransaction();
            var others = ImageNames(tx, exceptId: null);
            var cleanName = name is null ? FreeName(others) : CheckName(name, others);
            var position = Convert.ToInt32(Scalar(tx,
                "SELECT COALESCE(MAX(position) + 1, 0) FROM images WHERE asset_type = $type;", ("$type", Evlores.AssetType)),
                CultureInfo.InvariantCulture);
            Execute(tx, """
                INSERT INTO images (asset_type, name, position, width, height, pixels, updated_at)
                VALUES ($type, $name, $position, $width, $height, $pixels, $now);
                """,
                ("$type", Evlores.AssetType), ("$name", cleanName), ("$position", position),
                ("$width", cleanWidth), ("$height", cleanHeight), ("$pixels", pixels), ("$now", Now()));
            var id = Convert.ToInt64(Scalar(tx, "SELECT last_insert_rowid();"), CultureInfo.InvariantCulture);
            tx.Commit();
            return new ImageData(id, cleanName, cleanWidth, cleanHeight, pixels);
        }
    }

    /// <summary>Null when there is no such image.</summary>
    public ImageData? RenameImage(long id, string? name)
    {
        if (name is null) throw new InvalidInputException("The variable name is missing.");
        lock (_gate)
        {
            using var tx = _db.BeginTransaction();
            if (Scalar(tx, "SELECT 1 FROM images WHERE id = $id AND asset_type = $type;", ("$id", id), ("$type", Evlores.AssetType)) is null)
                return null;
            var cleanName = CheckName(name, ImageNames(tx, exceptId: id));
            Execute(tx, "UPDATE images SET name = $name, updated_at = $now WHERE id = $id;",
                ("$name", cleanName), ("$now", Now()), ("$id", id));
            tx.Commit();
        }
        return GetImage(id);
    }

    /// <summary>Replaces the image's size and pixels. False when there is no such image.</summary>
    public bool SetPixels(long id, int width, int height, string? pixels)
    {
        CheckSize(width, height);
        var bytes = PixelHex.Decode(pixels ?? "", width * height);
        lock (_gate)
        {
            return Execute(null, """
                UPDATE images SET width = $width, height = $height, pixels = $pixels, updated_at = $now
                WHERE id = $id AND asset_type = $type;
                """,
                ("$width", width), ("$height", height), ("$pixels", bytes), ("$now", Now()),
                ("$id", id), ("$type", Evlores.AssetType)) > 0;
        }
    }

    public bool DeleteImage(long id)
    {
        lock (_gate)
        {
            return Execute(null, "DELETE FROM images WHERE id = $id AND asset_type = $type;",
                ("$id", id), ("$type", Evlores.AssetType)) > 0;
        }
    }

    private static ImageData ReadImage(SqliteDataReader reader) =>
        new(reader.GetInt64(0), reader.GetString(1), reader.GetInt32(2), reader.GetInt32(3), (byte[])reader.GetValue(4));

    /// <summary>Every image's name: they all share res.h, whatever their type.</summary>
    private List<string> ImageNames(SqliteTransaction tx, long? exceptId)
    {
        using var command = Command(tx, "SELECT name FROM images WHERE id != $except;", ("$except", exceptId ?? -1));
        using var reader = command.ExecuteReader();
        var names = new List<string>();
        while (reader.Read()) names.Add(reader.GetString(0));
        return names;
    }

    private static string CheckName(string name, IReadOnlyCollection<string> others)
    {
        var clean = name.Trim();
        return CNames.Problem(clean, others) is { } problem ? throw new InvalidInputException(problem) : clean;
    }

    /// <summary>The first of image1, image2, ... that is free.</summary>
    private static string FreeName(IReadOnlyCollection<string> others)
    {
        for (var n = 1; ; n++)
        {
            var candidate = $"image{n}";
            if (CNames.Problem(candidate, others) is null) return candidate;
        }
    }

    private static void CheckSize(int width, int height)
    {
        if (width is < 1 or > Evlores.MaxWidth)
            throw new InvalidInputException($"The width must be 1-{Evlores.MaxWidth}.");
        if (height < Evlores.HeightStep || height > Evlores.MaxHeight || height % Evlores.HeightStep != 0)
            throw new InvalidInputException($"The height must be a multiple of {Evlores.HeightStep}, up to {Evlores.MaxHeight}.");
    }

    // ---------------------------------------------------------------- schema

    private void EnsureSchema()
    {
        if (Scalar(null, "SELECT 1 FROM sqlite_master WHERE type = 'table' AND name = 'meta';") is null)
        {
            using var create = _db.BeginTransaction();
            Execute(create, """
                CREATE TABLE meta (
                    key   TEXT PRIMARY KEY,
                    value TEXT NOT NULL
                );
                CREATE TABLE strings (
                    asset_type TEXT NOT NULL,
                    item       TEXT NOT NULL,
                    value      TEXT NOT NULL,
                    updated_at TEXT NOT NULL,
                    PRIMARY KEY (asset_type, item)
                );
                CREATE TABLE tiles (
                    asset_type TEXT    NOT NULL,
                    item       TEXT    NOT NULL,
                    code       INTEGER NOT NULL,
                    rows       BLOB    NOT NULL,
                    updated_at TEXT    NOT NULL,
                    PRIMARY KEY (asset_type, item, code)
                );
                """);
            Execute(create, ImagesTable);
            Execute(create, "INSERT INTO meta (key, value) VALUES ('schema_version', $version), ('created_at', $now);",
                ("$version", SchemaVersion.ToString(CultureInfo.InvariantCulture)), ("$now", Now()));
            create.Commit();
            return;
        }

        var stored = Scalar(null, "SELECT value FROM meta WHERE key = 'schema_version';") as string;
        var version = int.TryParse(stored, CultureInfo.InvariantCulture, out var parsed) ? parsed : 0;
        if (version is < 1 or > SchemaVersion)
            throw new InvalidOperationException($"{DatabasePath} is schema v{version}; this build knows v1-v{SchemaVersion}.");

        // Each upgrade step runs in its own transaction, along with the version it brings the database to.
        if (version == 1) Upgrade(2, tx => Execute(tx, ImagesTable));
        if (version <= 2)
        {
            Upgrade(3, tx =>
            {
                foreach (var table in new[] { "strings", "tiles" })
                {
                    Execute(tx, $"UPDATE {table} SET asset_type = $new WHERE asset_type = $old;",
                        ("$new", WavetextFont.AssetType), ("$old", RenamedFontType));
                }
            });
        }
    }

    private void Upgrade(int toVersion, Action<SqliteTransaction> step)
    {
        using var tx = _db.BeginTransaction();
        step(tx);
        Execute(tx, "UPDATE meta SET value = $version WHERE key = 'schema_version';",
            ("$version", toVersion.ToString(CultureInfo.InvariantCulture)));
        tx.Commit();
    }

    // --------------------------------------------------------------- helpers

    private int Execute(SqliteTransaction? tx, string sql, params (string Name, object Value)[] parameters)
    {
        using var command = Command(tx, sql, parameters);
        return command.ExecuteNonQuery();
    }

    private object? Scalar(SqliteTransaction? tx, string sql, params (string Name, object Value)[] parameters)
    {
        using var command = Command(tx, sql, parameters);
        return command.ExecuteScalar();
    }

    private SqliteCommand Command(SqliteTransaction? tx, string sql, params (string Name, object Value)[] parameters)
    {
        var command = _db.CreateCommand();
        command.CommandText = sql;
        command.Transaction = tx;
        foreach (var (name, value) in parameters) command.Parameters.AddWithValue(name, value);
        return command;
    }

    private static string Now() => DateTimeOffset.UtcNow.ToString("O", CultureInfo.InvariantCulture);
}
