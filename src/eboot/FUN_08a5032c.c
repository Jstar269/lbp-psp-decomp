/* LBPMATCH module=EBOOT.BIN start=0x08a5032c end=0x08a5037c symbol=FUN_08a5032c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Target {
  char pad[0x2c0];
  unsigned int unk_2c0;
  char pad2[0x50];
  unsigned int unk_314;
};

extern void FUN_08a9bff8();
extern void *FUN_08a9d390();

/* Stores the value twice (+0x2c0, +0x314); in between it builds a temporary object from it and passes that to FUN_08a9bff8. */
void FUN_08a5032c(struct Target *self, unsigned int *value)
{
  unsigned int scratch[8];

  self->unk_2c0 = *value;
  FUN_08a9d390(scratch, *value);
  FUN_08a9bff8(scratch);
  self->unk_314 = *value;
}
