namespace Resbuild.Server;

/// <summary>The microbee palette, in order: pixel value n shows as colour n.</summary>
public static class Microbee
{
    public static readonly int[][] Palette =
    [
        [0, 0, 0],
        [192, 0, 0],
        [0, 192, 0],
        [192, 192, 0],
        [0, 0, 192],
        [192, 0, 192],
        [0, 192, 192],
        [255, 255, 255],
        [96, 96, 96],
        [255, 0, 0],
        [0, 255, 0],
        [255, 255, 0],
        [0, 0, 255],
        [255, 0, 255],
        [0, 255, 255],
        [255, 255, 255],
    ];
}

/// <summary>wavetext_font: a string, and a monochrome 8 x 10 tile for each printable ASCII character.</summary>
public static class WavetextFont
{
    // How the database keys it.
    public const string AssetType = "wavetext_font";
    public const string TextItem = "string";
    public const string TilesItem = "tiles";

    public const int FirstCode = 32;
    public const int LastCode = 126;
    public const int TileWidth = 8;
    public const int TileHeight = 10;

    /// <summary>Each exported bitmap is the tile's rows padded with blank rows to this many bytes.</summary>
    public const int BitmapBytes = 16;

    public const int MaxTextLength = 4096;
}

/// <summary>evlores images: pixels twice as high as wide, any palette colour, an even height.</summary>
public static class Evlores
{
    public const string AssetType = "evlores_image";
    public const int HeightStep = 2;

    /// <summary>A new image is the size of the evlores screen.</summary>
    public const int DefaultWidth = 64;
    public const int DefaultHeight = 32;

    public const int MaxWidth = 256;
    public const int MaxHeight = 256;
}
