/* LBPMATCH module=EBOOT.BIN start=0x089e92d0 end=0x089e92fc symbol=FUN_089e92d0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Inner {
  char unk_00[0x14];
  unsigned int unk_14;
};

struct Obj {
  char unk_00[0x40];
  struct Inner *unk_40;
};

extern void FUN_08a9e0cc();

/* Passes the word at +0x14 of the inner object to FUN_08a9e0cc, then clears it. */
void FUN_089e92d0(struct Obj *self)
{
  struct Inner *inner;

  inner = self->unk_40;
  FUN_08a9e0cc(inner->unk_14);
  inner->unk_14 = 0;
  return;
}
