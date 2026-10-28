/* LBPMATCH module=EBOOT.BIN start=0x08874694 end=0x088746c4 symbol=FUN_08874694 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Three flag bytes at +0x15..+0x17: true only when all of them are clear. */
struct FlagBytes {
  char unk_00[0x15];
  unsigned char flag_15;
  unsigned char flag_16;
  unsigned char flag_17;
};

int FUN_08874694(struct FlagBytes *self)
{
  int all_clear;

  all_clear = 0;
  if ((self->flag_16 == '\0') &&
     ((all_clear = 1, self->flag_15 != '\0' || (self->flag_17 != '\0')))) {
    all_clear = 0;
  }
  return all_clear;
}
