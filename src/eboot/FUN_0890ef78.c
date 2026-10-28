/* LBPMATCH module=EBOOT.BIN start=0x0890ef78 end=0x0890efa8 symbol=FUN_0890ef78 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Dest {
  char pad_00[0x1818];
  unsigned int unk_1818;
};

struct Source {
  char pad_00[8];
  int unk_08;
};

extern unsigned int FUN_08ae11a4(int arg0, unsigned int arg1);

void FUN_0890ef78(struct Dest *dest, struct Source *source, unsigned int *key)
{
  unsigned int result;

  result = FUN_08ae11a4(source->unk_08, *key);
  dest->unk_1818 = result;
  return;
}
