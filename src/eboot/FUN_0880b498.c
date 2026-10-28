/* LBPMATCH module=EBOOT.BIN start=0x0880b498 end=0x0880b4b0 symbol=FUN_0880b498 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Inner {
  char pad_00[0x44];
  int unk_44;
};

struct Obj {
  char pad_00[0x2e4];
  struct Inner *inner;   /* +0x2e4, may be null */
};

enum { DEFAULT_VALUE = 0x3b };   /* returned when there is no object at +0x2e4 */

int FUN_0880b498(struct Obj *self)
{
  int value;

  value = DEFAULT_VALUE;
  if (self->inner != 0) {
    value = self->inner->unk_44;
  }
  return value;
}
