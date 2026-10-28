/* LBPMATCH module=EBOOT.BIN start=0x08a78564 end=0x08a78588 symbol=FUN_08a78564 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x680];
  unsigned char unk_680;
  char pad_681[3];
  float unk_684;
  int unk_688;
  float unk_68c;
};

/* Sets the flag at +0x680, clears +0x688 and stores -unk_684 / divisor into +0x68c. */
void FUN_08a78564(float divisor, struct Obj *self)
{
  self->unk_680 = 1;
  self->unk_688 = 0;
  self->unk_68c = (0.0f - self->unk_684) / divisor;
  return;
}
