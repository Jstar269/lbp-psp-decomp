/* LBPMATCH module=EBOOT.BIN start=0x08a7f4b0 end=0x08a7f4e8 symbol=FUN_08a7f4b0 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#define UNSET 0xffffffff

struct Obj {
  char unk_000[0x278];
  unsigned int unk_278;
};

extern int FUN_08a50fbc();
extern void FUN_08a537dc();

/* Same as FUN_08a4da24 for the value at +0x278. */
void FUN_08a7f4b0(struct Obj *self)
{
  int manager;

  manager = FUN_08a50fbc();
  FUN_08a537dc(manager, self->unk_278);
  self->unk_278 = UNSET;
  return;
}
