/* LBPMATCH module=EBOOT.BIN start=0x089c0cf0 end=0x089c0d2c symbol=FUN_089c0cf0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  int unk_00;
  int *unk_04;
};

extern void FUN_089ccf74();
extern void FUN_089cd228();

/* Forwards both arguments to the object held at +4. */
void FUN_089c0cf0(struct Obj *self, int first, int *second)
{
  FUN_089ccf74(self->unk_04, first);
  FUN_089cd228(self->unk_04, second);
  return;
}
