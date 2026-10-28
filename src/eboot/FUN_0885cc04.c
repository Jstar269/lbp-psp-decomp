/* LBPMATCH module=EBOOT.BIN start=0x0885cc04 end=0x0885cc5c symbol=FUN_0885cc04 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Obj {
  char pad_00[0xc];
  unsigned int *unk_0c;     /* created on first use */
};

extern unsigned int *FUN_0885cb44();
extern void FUN_0887dacc();

void FUN_0885cc04(struct Obj *self, int *arg1, int *arg2)
{
  if (self->unk_0c == 0) {
    self->unk_0c = FUN_0885cb44(self);
  }
  FUN_0887dacc(self->unk_0c, arg1, arg2);
}
