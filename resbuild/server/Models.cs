namespace Resbuild.Server;

/// <summary>
/// The font as stored: its text, and the rows of every tile that has a pixel set, by character
/// code. Each row is one byte, top to bottom, with the leftmost pixel in bit 7.
/// </summary>
public sealed record FontData(string Text, IReadOnlyDictionary<int, byte[]> Tiles);

/// <summary>An evlores image. <see cref="Pixels"/> holds one palette colour per pixel, row by row.</summary>
public sealed record ImageData(long Id, string Name, int Width, int Height, byte[] Pixels);

/// <summary>An image as the page sees it: the pixels are one hex digit each.</summary>
public sealed record ImageJson(long Id, string Name, int Width, int Height, string Pixels)
{
    public static ImageJson From(ImageData image) =>
        new(image.Id, image.Name, image.Width, image.Height, PixelHex.Encode(image.Pixels));
}

public sealed record TextRequest(string? Text);

/// <summary>Tiles to write, by character code. A tile with no pixel set is deleted.</summary>
public sealed record TilesRequest(Dictionary<int, int[]?>? Tiles);

/// <summary>A new image. Anything left out gets a default: a free name, the evlores screen size.</summary>
public sealed record NewImageRequest(string? Name, int? Width, int? Height);

public sealed record RenameRequest(string? Name);

/// <summary>An image's size and every pixel: resizing is sending a new size with its pixels.</summary>
public sealed record PixelsRequest(int Width, int Height, string? Pixels);

/// <summary>Input the page should not have sent; the client gets a 400 with the message.</summary>
public sealed class InvalidInputException(string message) : Exception(message);

/// <summary>Pixels on the wire: one hex digit (the palette colour) per pixel.</summary>
public static class PixelHex
{
    private const string Digits = "0123456789abcdef";

    public static string Encode(byte[] pixels) =>
        string.Create(pixels.Length, pixels, (text, source) =>
        {
            for (var i = 0; i < source.Length; i++) text[i] = Digits[source[i] & 0xf];
        });

    public static byte[] Decode(string text, int count)
    {
        if (text.Length != count)
            throw new InvalidInputException($"The image needs {count} pixels, one hex digit each; got {text.Length}.");
        var pixels = new byte[count];
        for (var i = 0; i < count; i++)
        {
            var value = Digits.IndexOf(char.ToLowerInvariant(text[i]));
            if (value < 0) throw new InvalidInputException($"Pixel {i} is not a hex digit.");
            pixels[i] = (byte)value;
        }
        return pixels;
    }
}
