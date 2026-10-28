/* LBPMATCH module=EBOOT.BIN start=0x088e6aa4 end=0x088e6acc symbol=FUN_088e6aa4 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Settings {
  char pad[0xa4];
  int unk_a4;
  char pad2[0x28];
  int flags;               /* +0xd0 */
};

/* Returns 1 (after updating +0xa4 if it differs) unless flag bit 23 is set (tested as the sign of flags << 8). */
int FUN_088e6aa4(struct Settings *self, int value)
{
  int result;

  result = 0;
  if ((-1 < (self->flags << 8)) && (result = 1, value != self->unk_a4)) {
    self->unk_a4 = value;
  }
  return result;
}
