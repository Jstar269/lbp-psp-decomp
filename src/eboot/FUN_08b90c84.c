/* LBPMATCH module=EBOOT.BIN start=0x08b90c84 end=0x08b90cc0 symbol=FUN_08b90c84 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Mangled-name reader state: only the input cursor at +0xc is used here. */
struct NameReader {
  char unk_00[0xc];
  const char *cursor;    /* +0xc: next input character */
};

extern void *FUN_08b908c0();

/* Consumes a leading "_Z" (the Itanium C++ mangling prefix) and hands the rest to FUN_08b908c0.
   The cursor has already moved past the characters read when the prefix does not match. */
void *FUN_08b90c84(struct NameReader *reader, int arg)
{
  const char *p;
  char c;

  p = reader->cursor;
  c = *p;
  reader->cursor = p + 1;
  if (c == '_') {
    c = p[1];
    reader->cursor = p + 2;
    if (c == 'Z') {
      return FUN_08b908c0(reader, arg);
    }
  }
  return 0;
}
