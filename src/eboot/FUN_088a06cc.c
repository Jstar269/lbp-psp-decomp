/* LBPMATCH module=EBOOT.BIN start=0x088a06cc end=0x088a06e4 symbol=FUN_088a06cc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Inner {
  char unk_00[0xc];
  int unk_0c;
};

struct Holder {
  struct Inner *inner;
};

/* Word at +0xc of the pointed-to object, or 0 when there is none. */
int FUN_088a06cc(struct Holder *holder)
{
  int result;

  result = 0;
  if (holder->inner != 0) {
    result = holder->inner->unk_0c;
  }
  return result;
}
