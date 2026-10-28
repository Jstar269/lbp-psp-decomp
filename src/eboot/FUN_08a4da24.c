/* LBPMATCH module=EBOOT.BIN start=0x08a4da24 end=0x08a4da5c symbol=FUN_08a4da24 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#define UNSET 0xffffffff

struct Obj {
  char unk_000[0x2f4];
  unsigned int unk_2f4;
};

extern int FUN_08a50fbc();
extern void FUN_08a537dc();

/* Hands the value at +0x2f4 to FUN_08a537dc (with FUN_08a50fbc result), then resets it to -1. */
void FUN_08a4da24(struct Obj *self)
{
  int manager;

  manager = FUN_08a50fbc();
  FUN_08a537dc(manager, self->unk_2f4);
  self->unk_2f4 = UNSET;
  return;
}
