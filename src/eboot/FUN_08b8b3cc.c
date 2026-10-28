/* LBPMATCH module=EBOOT.BIN start=0x08b8b3cc end=0x08b8b41c symbol=FUN_08b8b3cc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Calls FUN_08b8ad1c with the byte distance from the start of the buffer to `position`, then marks the word
   before the (possibly relocated) buffer as -1 and returns the position re-based onto the buffer. */
extern void FUN_08b8ad1c();

char *FUN_08b8b3cc(char **buffer_ref, char *position)
{
  char *old_start;
  char *new_start;

  old_start = *buffer_ref;
  FUN_08b8ad1c(buffer_ref, position - old_start, 1, 0);
  new_start = *buffer_ref;
  *(int *)(new_start - 4) = -1;
  return new_start + (position - old_start);
}
