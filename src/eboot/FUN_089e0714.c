/* LBPMATCH module=EBOOT.BIN start=0x089e0714 end=0x089e077c symbol=FUN_089e0714 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g10); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Passes `arg` on to the two child objects (+0x10 then +0xc) unless the byte flag at +0x14 is set;
   returns the inverted flag. */
struct TwoChildren {
  char pad[0xc];
  int *child_0c;
  int *child_10;
  unsigned char flag_14;
};

extern void FUN_0896aeec();

unsigned char FUN_089e0714(struct TwoChildren *self, int arg)
{
  if (self->flag_14 == '\0') {
    if (self->child_10 != (int *)0x0) {
      FUN_0896aeec(self->child_10, arg);
    }
    if (self->child_0c != (int *)0x0) {
      FUN_0896aeec(self->child_0c, arg);
    }
  }
  return self->flag_14 ^ 1;
}
