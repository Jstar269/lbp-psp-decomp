/* LBPMATCH module=EBOOT.BIN start=0x08a4c8f8 end=0x08a4c918 symbol=FUN_08a4c8f8 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern void FUN_08a4bb3c();
extern void FUN_08a4c794();

/* The word at +0x34 of the object self points at selects between the two helpers. */
struct InnerObj {
  unsigned char unk_00[0x34];
  int unk_34;   /* +0x34 */
};

struct OuterObj {
  struct InnerObj *inner;
};

void FUN_08a4c8f8(struct OuterObj *self, int arg)
{
  if (self->inner->unk_34 != 0) {
    FUN_08a4c794(arg);
    return;
  }
  FUN_08a4bb3c(arg);
}
