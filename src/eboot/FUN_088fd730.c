/* LBPMATCH module=EBOOT.BIN start=0x088fd730 end=0x088fd758 symbol=FUN_088fd730 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_088fd6c0();

/* Object with a changeable value at +0x1c; a byte at +0x18 suppresses the change notification. */
struct ValueHolder {
  char unk_00[0x18];
  unsigned char suppress;
  char unk_19[3];
  int value;
};

void FUN_088fd730(struct ValueHolder *self,int new_value)
{
  int old_value;

  old_value = self->value;
  self->value = new_value;
  if ((self->suppress == '\0') && (old_value != new_value)) {
    FUN_088fd6c0(self);
    return;
  }
  return;
}
