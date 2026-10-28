/* LBPMATCH module=EBOOT.BIN start=0x0888a5c4 end=0x0888a5ec symbol=FUN_0888a5c4 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0x4d4];
  int mode;                      /* +0x4d4 */
  char unk_4d8;
  unsigned char flag;            /* +0x4d9 */
};

/* A set flag or mode 8 resets the mode to 5; the flag is cleared in all cases. */
void FUN_0888a5c4(struct Object *self)
{
  if ((self->flag != 0) || (self->mode == 8)) {
    self->mode = 5;
  }
  self->flag = 0;
}
