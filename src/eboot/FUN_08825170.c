/* LBPMATCH module=EBOOT.BIN start=0x08825170 end=0x0882519c symbol=FUN_08825170 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Stores the byte at +0x18 of `self` and mirrors it into the byte at +0x2070 of the object returned by
   FUN_08a10f1c. */
struct HasFlag18 {
  char pad[0x18];
  unsigned char flag;        /* +0x18 */
};

struct Shared2070 {
  char pad[0x2070];
  unsigned char flag;        /* +0x2070 */
};

extern struct Shared2070 *FUN_08a10f1c();

void FUN_08825170(struct HasFlag18 *self, unsigned char flag)
{
  struct Shared2070 *shared;

  self->flag = flag;
  shared = FUN_08a10f1c();
  shared->flag = flag;
  return;
}
