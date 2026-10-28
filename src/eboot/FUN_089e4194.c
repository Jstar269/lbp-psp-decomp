/* LBPMATCH module=EBOOT.BIN start=0x089e4194 end=0x089e41e0 symbol=FUN_089e4194 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x9c];
  void *unk_9c;
  char unk_a0[4];
  char unk_a4;
};

extern void FUN_089e2f08();
extern void FUN_089e3ff8();
extern void FUN_08b88f70();

/* FUN_08b88f70 is skipped when the word at +0x9c holds its own address. */
void FUN_089e4194(struct Obj *self)
{
  if (self->unk_9c != &self->unk_9c) {
    FUN_08b88f70(&self->unk_a4, self->unk_9c, &self->unk_9c);
  }
  FUN_089e3ff8(self);
  FUN_089e2f08(self);
  return;
}
