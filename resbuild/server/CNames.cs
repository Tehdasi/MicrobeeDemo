using System.Text.RegularExpressions;

namespace Resbuild.Server;

/// <summary>What an image's variable name must be for res.h and res.c to still compile.</summary>
public static partial class CNames
{
    public const int MaxLength = 32;

    /// <summary>
    /// Names no image may take: C and SDCC keywords, the macros the demo's misc.h defines, and
    /// everything res.h declares for other assets.
    /// </summary>
    public static readonly IReadOnlyList<string> Reserved =
    [
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum",
        "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while", "bool", "true", "false", "nullptr", "constexpr", "typeof", "alignas", "alignof",
        "static_assert", "thread_local", "asm", "at", "sfr", "sbit", "bit", "interrupt", "critical", "naked",
        "reentrant", "using", "code", "data", "NULL",
        "byte", "dbyte", "MIN", "MAX", "SCREEN_X", "SCREEN_Y",
        ResExport.Guard, .. ResExport.FontSymbols,
    ];

    [GeneratedRegex("^[A-Za-z_][A-Za-z0-9_]*$")]
    private static partial Regex Identifier();

    /// <summary>Everything an image's export declares: its array and its size macros.</summary>
    public static IEnumerable<string> Symbols(string name)
    {
        var upper = name.ToUpperInvariant();
        return [name, upper + "_WIDTH", upper + "_HEIGHT"];
    }

    /// <summary>Why <paramref name="name"/> cannot be an image's variable name, or null when it can.</summary>
    public static string? Problem(string name, IReadOnlyCollection<string> otherImages)
    {
        if (name.Length == 0) return "The variable name cannot be empty.";
        if (name.Length > MaxLength) return $"The variable name can be at most {MaxLength} characters.";
        if (!Identifier().IsMatch(name)) return "Use letters, digits and _, not starting with a digit.";
        if (name.StartsWith("__", StringComparison.Ordinal) || (name.Length > 1 && name[0] == '_' && char.IsAsciiLetterUpper(name[1])))
            return "Names starting with __, or _ and a capital, are reserved in C.";

        // The size macros are upper case, so "skull" and "Skull" would both define SKULL_WIDTH.
        if (otherImages.FirstOrDefault(other => string.Equals(other, name, StringComparison.OrdinalIgnoreCase)) is { } twin)
            return $"Another image is already called {twin}.";

        if (Reserved.Contains(name)) return $"{name} is a C keyword or a name the demo already uses.";
        var taken = new HashSet<string>(Reserved.Concat(otherImages.SelectMany(Symbols)), StringComparer.Ordinal);
        return Symbols(name).FirstOrDefault(taken.Contains) is { } clash
            ? $"{name} would also declare {clash}, which is already taken."
            : null;
    }
}
