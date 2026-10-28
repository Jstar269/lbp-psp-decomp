/* LBPMATCH module=EBOOT.BIN start=0x088e657c end=0x088e65e4 symbol=FUN_088e657c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int DAT_08bf03b8;
extern int FUN_0896f7d0();
extern void FUN_08970494();

/* Object with a saved copy of a state value at +0x298. */
struct StateHolder {
  char unk_00[0x298];
  int saved_state;
};

void FUN_088e657c(struct StateHolder *self)
{
  int current;
  int owner;

  current = FUN_0896f7d0(DAT_08bf03b8);
  if (current != 0x47) {
    current = FUN_0896f7d0(DAT_08bf03b8);
    owner = DAT_08bf03b8;
    self->saved_state = current;
    FUN_08970494(owner,1,0x47);
    return;
  }
  return;
}
