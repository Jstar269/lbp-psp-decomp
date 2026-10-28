/* LBPMATCH module=EBOOT.BIN start=0x0890c334 end=0x0890c37c symbol=FUN_0890c334 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0x241];
  unsigned char unk_241;
  char unk_242[2];
  unsigned char unk_244;
};

extern unsigned int FUN_0890c1b4();

/* Sets the flag at +0x244 once FUN_0890c1b4 accepts, while neither +0x241 nor +0x244 is set. */
void FUN_0890c334(struct Object *self)
{
  int accepted;

  if (((self->unk_241 == 0) && (self->unk_244 == 0)) &&
     (accepted = FUN_0890c1b4(self), accepted != 0)) {
    self->unk_244 = 1;
  }
}
