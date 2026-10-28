/* LBPMATCH module=EBOOT.BIN start=0x0889bca4 end=0x0889bd00 symbol=FUN_0889bca4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Removes `item`: tells the FUN_0889d194 object via FUN_0889cfac, calls virtual slot 0x20 of `self`, and
   decrements the count word at +4. */
struct VCounted {
  void **vtable;             /* +0 */
  int count;                 /* +4 */
};

extern void FUN_0889cfac();
extern unsigned int *FUN_0889d194();

void FUN_0889bca4(struct VCounted *self, unsigned int item)
{
  unsigned int *other;

  other = FUN_0889d194();
  FUN_0889cfac(other, item);
  ((void (*)(struct VCounted *, unsigned int))self->vtable[0x20 / 4])(self, item);
  self->count = self->count + -1;
  return;
}
