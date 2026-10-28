/* LBPMATCH module=EBOOT.BIN start=0x08a89734 end=0x08a89778 symbol=FUN_08a89734 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0xb4];
  unsigned int unk_b4;
  unsigned int unk_b8;
};

extern void FUN_08a35244();
extern void FUN_08a352f8();

/* Runs FUN_08a352f8 on the object, then FUN_08a35244 on the words at +0xb4 and +0xb8. */
void FUN_08a89734(struct Object *self, unsigned int arg, int ctx)
{
  FUN_08a352f8(self, arg, ctx);
  FUN_08a35244(&self->unk_b4, ctx);
  FUN_08a35244(&self->unk_b8, ctx);
}
