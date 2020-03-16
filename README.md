# PE-Dump-Fixer

Check release for ready-to-use executable.

Instead of realigning the sections to match the raw header, this will fix the header raw to virtual so that previously found offsets in virtual space still apply to the dump and dont have to be recalculated.

Usage:

- Drag and Drop the dump onto the fixer.exe

or
- Open cmd, direct to the correct folder and type: Dump-Fixer "filename.extension"
E.g. Dump-Fixer "dump.dll"
