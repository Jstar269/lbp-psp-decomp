/* LBPMATCH module=EBOOT.BIN start=0x08954c60 end=0x08954ca4 symbol=FUN_08954c60 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Releases the object: calls the callback at +0x10 with the pointer at +4 and clears the pointer, or falls
   back to FUN_0894fb20 when there is no callback. */
struct Releasable {
  char pad[4];
  unsigned int data;         /* +4 */
  char pad2[8];
  void (*release)(unsigned int);   /* +0x10 */
};

extern void FUN_0894fb20();

void FUN_08954c60(struct Releasable *self)
{
  if (self->release != 0) {
    self->release(self->data);
    self->data = 0;
    return;
  }
  FUN_0894fb20(self);
  return;
}
