/* LBPMATCH module=EBOOT.BIN start=0x08aa0b70 end=0x08aa0bcc symbol=FUN_08aa0b70 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Vec {
  unsigned int *unk_00;
  unsigned int *end;
};

extern unsigned int *FUN_08aa0aa8();

/* Remove one element: shift the tail [pos + 1, end) down over pos, then drop the last slot. */
unsigned int *FUN_08aa0b70(struct Vec *vec, unsigned int *pos)
{
  if (pos + 1 != vec->end) {
    FUN_08aa0aa8(pos + 1, vec->end, pos);
  }
  vec->end = vec->end - 1;
  return pos;
}
