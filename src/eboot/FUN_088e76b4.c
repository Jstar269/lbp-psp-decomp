/* LBPMATCH module=EBOOT.BIN start=0x088e76b4 end=0x088e76dc symbol=FUN_088e76b4 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Settings {
  char pad[0xb0];
  int unk_b0;
  char pad2[0x1c];
  int flags;               /* +0xd0 */
};

/* Returns 1 (after updating +0xb0 if it differs) unless flag bit 14 is set (tested as the sign of flags << 17). */
int FUN_088e76b4(struct Settings *self, int value)
{
  int result;

  result = 0;
  if ((-1 < (self->flags << 0x11)) && (result = 1, value != self->unk_b0)) {
    self->unk_b0 = value;
  }
  return result;
}
