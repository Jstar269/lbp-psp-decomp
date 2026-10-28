/* LBPMATCH module=EBOOT.BIN start=0x0886c714 end=0x0886c720 symbol=FUN_0886c714 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Two values stored back to back at +0x1c and +0x20. */
struct PairAt1c {
  char unk_00[0x1c];
  unsigned int first;
  unsigned int second;
};

void FUN_0886c714(struct PairAt1c *self,unsigned int first,unsigned int second)
{
  self->second = second;
  self->first = first;
  return;
}
