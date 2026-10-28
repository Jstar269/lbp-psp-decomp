/* LBPMATCH module=EBOOT.BIN start=0x08a352f8 end=0x08a3535c symbol=FUN_08a352f8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x3c];
  int unk_3c;
  char unk_40[0x50];
  unsigned int unk_90;
};

extern void FUN_08a35244();

/* Applies FUN_08a35244 to the word at +0x90, and to the word at +0x3c unless it is -1. */
void FUN_08a352f8(struct Obj *self, int unused, int arg)
{
  unsigned int *other;

  FUN_08a35244(&self->unk_90, arg);
  other = (unsigned int *)&self->unk_3c;
  if (self->unk_3c != -1) {
    FUN_08a35244(other, arg);
  }
  return;
}
