/* LBPMATCH module=EBOOT.BIN start=0x08b8b37c end=0x08b8b3cc symbol=FUN_08b8b37c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

extern void FUN_08b8ad1c();

/* *str is the data pointer (the callee may reallocate it, so positions are kept as offsets from the old one).
   After the call the word in front of the data is set to -1; the result is `pos` rebased onto the new data. */
char *FUN_08b8b37c(char **str, char *pos, char *end)
{
  char *old_data;
  char *data;

  old_data = *str;
  FUN_08b8ad1c(str, pos - old_data, end - pos, 0);
  data = *str;
  ((int *)data)[-1] = -1;
  return data + (pos - old_data);
}
