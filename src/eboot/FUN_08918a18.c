/* LBPMATCH module=EBOOT.BIN start=0x08918a18 end=0x08918a74 symbol=FUN_08918a18 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern void FUN_08ac9f80();
extern void FUN_08ac9fc4();

/* Helpers FUN_08ac9f80 / FUN_08ac9fc4 each take the handle at +8 and are called in opposite states. */
struct ToggleObj {
  unsigned char unk_00[8];
  void *handle;               /* +8 */
  unsigned char toggle_allowed;   /* +0xc: toggle is allowed */
  unsigned char unk_0d;
  unsigned char state;        /* +0xe: current on/off state */
};

/* Flips the on/off state when toggling is allowed; returns the (new) state. */
unsigned char FUN_08918a18(struct ToggleObj *self)
{
  if (self->toggle_allowed != 0) {
    if (self->state == 0) {
      FUN_08ac9f80(self->handle);
      self->state = 1;
    }
    else {
      FUN_08ac9fc4(self->handle);
      self->state = 0;
    }
  }
  return self->state;
}
