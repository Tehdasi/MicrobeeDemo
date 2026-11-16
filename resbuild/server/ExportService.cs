using System.Globalization;
using System.Text;

namespace Resbuild.Server;

public sealed record ExportStatus(string Directory, bool Pending, string? WrittenAt, string? Error, IReadOnlyList<ExportFileStatus> Files);

public sealed record ExportFileStatus(string Name, string Path, string Content, bool UpToDate);

/// <summary>
/// Keeps res.h and res.c in step with the database, lazily: each edit marks the export dirty, and
/// once edits pause for a second both files are regenerated from every asset. A file is only
/// rewritten when its content changes (so the demo's build only sees real changes), and through
/// a temporary file (so a build never reads half of one). The files are brought up to date on
/// startup, and anything still waiting is written on shutdown.
/// </summary>
public sealed class ExportService : IHostedService, IDisposable
{
    private static readonly TimeSpan Delay = TimeSpan.FromSeconds(1);
    private static readonly TimeSpan RetryDelay = TimeSpan.FromSeconds(5);
    private static readonly Encoding Utf8 = new UTF8Encoding(encoderShouldEmitUTF8Identifier: false);

    private readonly AssetStore _store;
    private readonly ILogger<ExportService> _logger;
    private readonly Timer _timer;
    private readonly Lock _gate = new();      // _dirty, _writtenAt, _error
    private readonly Lock _writeGate = new(); // one export at a time
    private bool _dirty;
    private string? _writtenAt;
    private string? _error;

    public ExportService(AssetStore store, string directory, ILogger<ExportService> logger)
    {
        _store = store;
        _logger = logger;
        Directory = Path.GetFullPath(directory);
        _timer = new Timer(_ => Flush(), null, Timeout.Infinite, Timeout.Infinite);
    }

    public string Directory { get; }

    /// <summary>An asset changed: the files are written once edits pause.</summary>
    public void MarkDirty()
    {
        lock (_gate)
        {
            _dirty = true;
            _timer.Change(Delay, Timeout.InfiniteTimeSpan);
        }
    }

    /// <summary>Writes the files now if anything changed since they were last written.</summary>
    public void Flush()
    {
        lock (_writeGate)
        {
            lock (_gate)
            {
                if (!_dirty) return;
                _dirty = false;
            }

            try
            {
                System.IO.Directory.CreateDirectory(Directory);
                var written = Generate().Where(file => WriteIfChanged(Path.Combine(Directory, file.Name), file.Content)).ToList();
                if (written.Count > 0) _logger.LogInformation("Wrote {Files}", string.Join(", ", written.Select(file => file.Name)));
                lock (_gate)
                {
                    if (written.Count > 0) _writtenAt = DateTimeOffset.UtcNow.ToString("O", CultureInfo.InvariantCulture);
                    _error = null;
                }
            }
            catch (Exception ex)
            {
                // This runs on a timer thread, where an escaping exception would end the server.
                _logger.LogError(ex, "Could not write the export to {Directory}", Directory);
                lock (_gate)
                {
                    _error = ex.Message;
                    _dirty = true;
                    _timer.Change(RetryDelay, Timeout.InfiniteTimeSpan);
                }
            }
        }
    }

    /// <summary>The files as generated from what is stored now, and whether the disk has caught up.</summary>
    public ExportStatus Status()
    {
        var files = Generate()
            .Select(file =>
            {
                var path = Path.Combine(Directory, file.Name);
                return new ExportFileStatus(file.Name, path, file.Content, IsCurrent(path, file.Content));
            })
            .ToList();
        lock (_gate) return new ExportStatus(Directory, _dirty, _writtenAt, _error, files);
    }

    public Task StartAsync(CancellationToken cancellationToken)
    {
        _logger.LogInformation("Exporting to {Directory}", Directory);
        // Catch up with the database, e.g. after the exporter itself changed.
        lock (_gate) _dirty = true;
        Flush();
        return Task.CompletedTask;
    }

    public Task StopAsync(CancellationToken cancellationToken)
    {
        _timer.Change(Timeout.Infinite, Timeout.Infinite);
        Flush();
        return Task.CompletedTask;
    }

    public void Dispose() => _timer.Dispose();

    private IReadOnlyList<ExportFile> Generate() => ResExport.Build(_store.GetFont(), _store.GetImages());

    private static bool WriteIfChanged(string path, string content)
    {
        if (IsCurrent(path, content)) return false;
        var temporary = path + ".tmp";
        File.WriteAllText(temporary, content, Utf8);
        File.Move(temporary, path, overwrite: true);
        return true;
    }

    private static bool IsCurrent(string path, string content)
    {
        try
        {
            return File.Exists(path) && File.ReadAllText(path, Utf8) == content;
        }
        catch (IOException)
        {
            return false;
        }
    }
}
