/* LBPMATCH module=EBOOT.BIN start=0x0880b0d4 end=0x0880b0ec symbol=FUN_0880b0d4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Inner {
  char pad_00[0x70];
  unsigned char unk_70;
};

struct Obj {
  char pad_00[0xc];
  struct Inner *inner;   /* +0xc, may be null */
};

/* Returns the byte at +0x70 of the object at +0xc, or 0 when there is none. */
unsigned char FUN_0880b0d4(struct Obj *self)
{
  unsigned char value;

  value = 0;
  if (self->inner != 0) {
    value = self->inner->unk_70;
  }
  return value;
}
