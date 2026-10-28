/* LBPMATCH module=EBOOT.BIN start=0x089862ac end=0x0898631c symbol=FUN_089862ac lang=c99 cc=gcc402x-Os rodata=0x08bbee60 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Node {
  char pad[0x24];
  int unk_24;
};

extern struct Node *FUN_0898117c();
extern void FUN_0898617c();
extern struct Node *FUN_08982774();
extern struct Node *FUN_08983c80();
extern unsigned int FUN_08adbd60();

void FUN_089862ac(struct Node *self)
{
  unsigned int name_hash;
  struct Node *shape;

  self->unk_24 = 6;
  name_hash = FUN_08adbd60((unsigned char *)"paint_shapes");
  shape = FUN_0898117c(~name_hash);
  FUN_0898617c(shape);
  shape = FUN_08982774(self, 6, shape, '\x01', (unsigned int *)0);
  FUN_08983c80(self, shape);
}
