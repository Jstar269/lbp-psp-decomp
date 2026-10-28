/* LBPMATCH module=EBOOT.BIN start=0x089d1dfc end=0x089d1e3c symbol=FUN_089d1dfc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Calls FUN_089771cc on the sub-object at +0x18 and, when it reports success, sets flag 8 in the flags word at +4. */
#define FLAG_0x8 0x8

struct Owner18 {
  int unk_00;
  unsigned int flags;        /* +4 */
  char pad[0x10];
  int sub_object[1];         /* +0x18: embedded sub-object */
};

extern int FUN_089771cc();

void FUN_089d1dfc(struct Owner18 *self, unsigned int *arg, unsigned char flag)
{
  int result;

  result = FUN_089771cc(self->sub_object, arg, flag);
  if (result != 0) {
    self->flags = self->flags | FLAG_0x8;
  }
  return;
}
