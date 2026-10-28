/* LBPMATCH module=EBOOT.BIN start=0x08a9b810 end=0x08a9b820 symbol=FUN_08a9b810 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

struct WordTriple {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
};

void FUN_08a9b810(struct WordTriple *self,unsigned int a,unsigned int b,unsigned int c)
{
  self->unk_08 = c;
  self->unk_00 = a;
  self->unk_04 = b;
  return;
}
