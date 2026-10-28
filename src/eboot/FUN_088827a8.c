/* LBPMATCH module=EBOOT.BIN start=0x088827a8 end=0x088827c0 symbol=FUN_088827a8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Global state object; a word pair at +0x4b8 is read out. */
struct Globals {
  char unk_00[0x4b8];
  unsigned int unk_4b8;
  unsigned int unk_4bc;
};

extern struct Globals *DAT_08bee030;

unsigned int FUN_088827a8(unsigned int *out)
{
  unsigned int first;

  first = DAT_08bee030->unk_4b8;
  *out = DAT_08bee030->unk_4bc;
  return first;
}
