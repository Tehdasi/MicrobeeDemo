"""Point at the line that makes sdasz80 crash.

SDCC 4.6.0's Windows sdasz80 crashes (exit code 0xC0000028) instead of
reporting some syntax errors - e.g. a missing comma in "jp nz label" or a
bad index like "(ix+)" - and prints nothing, so a typo in inline __asm shows
up only as a failed build.  This assembles ever longer prefixes of the .asm
file to find the first line that crashes it, then reports that line and the
C source line it came from.  If the assembler doesn't crash, it stays quiet
(SDCC has already shown any normal errors).

Usage: python asmcheck.py file.asm
"""
import os
import re
import subprocess
import sys
import tempfile

C_LINE = re.compile(r"^;(.+?):(\d+):")


def crashes(lines, tmpdir):
    src = os.path.join(tmpdir, "probe.asm")
    with open(src, "w") as f:
        f.writelines(lines)
    result = subprocess.run(["sdasz80", "-o", os.path.join(tmpdir, "probe.rel"), src],
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return not 0 <= result.returncode <= 255   # a Windows exception, not an exit status


def first_crashing_line(lines, tmpdir):
    """Index of the line whose inclusion makes the assembler crash."""
    good, bad = 0, len(lines)       # prefix lengths: good doesn't crash, bad does
    while bad - good > 1:
        mid = (good + bad) // 2
        if crashes(lines[:mid], tmpdir):
            bad = mid
        else:
            good = mid
    return bad - 1


def normalise(text):
    return " ".join(text.split())


def c_location(lines, index):
    """C file and line for asm line `index`, using SDCC's ';file:line:' comments.

    Inline asm is emitted after the comment for its __endasm line, so search
    back from there for the same text to get the exact line."""
    for i in range(index, -1, -1):
        m = C_LINE.match(lines[i])
        if m:
            cfile, cline = m.group(1), int(m.group(2))
            break
    else:
        return None, None
    try:
        with open(cfile) as f:
            source = f.readlines()
    except OSError:
        return cfile, cline
    wanted = normalise(lines[index])
    for n in range(min(cline, len(source)), 0, -1):
        if normalise(source[n - 1]) == wanted:
            return cfile, n
    return cfile, cline


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    asm = sys.argv[1]
    with open(asm) as f:
        lines = f.readlines()

    with tempfile.TemporaryDirectory() as tmpdir:
        if not crashes(lines, tmpdir):
            return
        index = first_crashing_line(lines, tmpdir)

    text = lines[index].strip()
    cfile, cline = c_location(lines, index)
    where = f"{cfile}:{cline}" if cfile else f"{asm}:{index + 1}"
    print(f"{where}: error: assembler crashed on \"{text}\" ({asm}:{index + 1})")
    print("    sdasz80 crashes instead of reporting some syntax errors - check this line,")
    print("    e.g. for a missing comma (\"jp nz, label\") or a bad operand.")
    sys.exit(1)


if __name__ == "__main__":
    main()
