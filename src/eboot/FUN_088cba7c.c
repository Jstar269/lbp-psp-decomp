/* LBPMATCH module=EBOOT.BIN start=0x088cba7c end=0x088cbaa8 symbol=FUN_088cba7c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Inner {
  char pad_00[0x40];
  int unk_40;
};

struct Outer {
  struct Inner *inner;
};

struct Result {
  char pad_00[0x14];
  int unk_14;
  char pad_18[4];
  int unk_1c;
};

/* Sets the word at +0x14 of `result` to 0 (and bumps the word at +0x1c) when inner->unk_40 is zero, else to 5. */
void FUN_088cba7c(struct Outer *outer, struct Result *result)
{
  if (outer->inner->unk_40 == 0) {
    result->unk_14 = 0;
    result->unk_1c = result->unk_1c + 1;
    return;
  }
  result->unk_14 = 5;
  return;
}
