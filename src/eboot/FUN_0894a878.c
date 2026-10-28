/* LBPMATCH module=EBOOT.BIN start=0x0894a878 end=0x0894a8d8 symbol=FUN_0894a878 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Vec {
  unsigned int unk_00;
  char *end;
};

extern unsigned int *FUN_08b9e8cc();

/* Erase [first, last): move the tail [last, end) down to first, then pull `end` back by the erased length. */
char *FUN_0894a878(struct Vec *vec, char *first, char *last)
{
  FUN_08b9e8cc(first, last, vec->end - last);
  vec->end = vec->end - (last - first);
  return first;
}
