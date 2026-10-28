/* LBPMATCH module=EBOOT.BIN start=0x08b8fb14 end=0x08b8fb5c symbol=FUN_08b8fb14 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Scan {
  char pad_00[0xc];
  char *cursor;              /* current position in the text being scanned */
};

extern int FUN_08b8f7f0();

/* Optional '_' prefix: skip it and run FUN_08b8f7f0; fails (0) only when that returns a negative value. */
int FUN_08b8fb14(struct Scan *scan)
{
  int status;
  int ok;

  if (*scan->cursor == '_') {
    scan->cursor = scan->cursor + 1;
    status = FUN_08b8f7f0(scan);
    ok = 0;
    if (-1 < status) {
      ok = 1;
    }
  }
  else {
    ok = 1;
  }
  return ok;
}
