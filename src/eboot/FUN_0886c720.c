/* LBPMATCH module=EBOOT.BIN start=0x0886c720 end=0x0886c758 symbol=FUN_0886c720 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Invokes the optional callback at +0x1c with (self, argument at +0x20), then sets the state word at +0xc to 2. */
struct Callback1c {
  char pad[0xc];
  int state;                 /* +0xc */
  char unk_10[0xc];
  void (*callback)(struct Callback1c *, unsigned int);   /* +0x1c */
  unsigned int callback_arg; /* +0x20 */
};

void FUN_0886c720(struct Callback1c *self)
{
  if (self->callback != 0) {
    self->callback(self, self->callback_arg);
  }
  self->state = 2;
  return;
}
