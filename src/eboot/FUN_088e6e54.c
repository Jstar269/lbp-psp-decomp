/* LBPMATCH module=EBOOT.BIN start=0x088e6e54 end=0x088e6e7c symbol=FUN_088e6e54 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Settings {
  char pad[0x44];
  int mode;                /* +0x44 */
  char pad2[0x58];
  int unk_a0;
};

/* Returns 1 (after updating +0xa0 if it differs) only when mode is 0x19. */
int FUN_088e6e54(struct Settings *self, int value)
{
  int result;

  result = 0;
  if ((self->mode == 0x19) && (result = 1, value != self->unk_a0)) {
    self->unk_a0 = value;
  }
  return result;
}
