/* LBPMATCH module=EBOOT.BIN start=0x08868cf0 end=0x08868d24 symbol=FUN_08868cf0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x1cc];
  void (*callback)(void *arg);   /* +0x1cc, optional */
  void *callback_arg;            /* +0x1d0 */
};

extern void FUN_08878dc8(struct Obj *self);

void FUN_08868cf0(struct Obj *self)
{
  if (self->callback != 0) {
    self->callback(self->callback_arg);
  }
  FUN_08878dc8(self);
  return;
}
