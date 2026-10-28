/* LBPMATCH module=EBOOT.BIN start=0x08a58bc0 end=0x08a58bd8 symbol=FUN_08a58bc0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Inner {
  char unk_00[8];
  unsigned int unk_08;
};

struct Outer {
  char unk_00[0x9c];
  struct Inner *inner;   /* +0x9c: may be null */
};

/* Reads the word at +8 of the object linked at +0x9c, or 0 when there is none. */
unsigned int FUN_08a58bc0(struct Outer *self)
{
  return self->inner != 0 ? self->inner->unk_08 : 0;
}
