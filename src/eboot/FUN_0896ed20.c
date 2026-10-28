/* LBPMATCH module=EBOOT.BIN start=0x0896ed20 end=0x0896ed38 symbol=FUN_0896ed20 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Inner {
  char unk_00[0x2c];
  unsigned int unk_2c;
};

struct Outer {
  char unk_00[0xc];
  struct Inner *inner;   /* +0xc: may be null */
};

/* Reads the word at +0x2c of the object linked at +0xc, or 0 when there is none. */
unsigned int FUN_0896ed20(struct Outer *self)
{
  return self->inner != 0 ? self->inner->unk_2c : 0;
}
