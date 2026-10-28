/* LBPMATCH module=EBOOT.BIN start=0x08b8b274 end=0x08b8b2cc symbol=FUN_08b8b274 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

extern char **FUN_08b8b160();

/* *str is the data pointer (the callee may reallocate it, so the position is kept as an offset). After the call
   the word in front of the data is set to -1; the result is `pos` rebased onto the new data. */
char *FUN_08b8b274(char **str, char *pos, char ch)
{
  char *old_data;
  char *data;

  old_data = *str;
  FUN_08b8b160(str, pos - old_data, 0, 1, ch);
  data = *str;
  ((int *)data)[-1] = -1;
  return data + (pos - old_data);
}
