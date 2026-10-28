/* LBPMATCH module=EBOOT.BIN start=0x0889b6a0 end=0x0889b6e0 symbol=FUN_0889b6a0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Object with a pending-callback pointer at +0x14 that runs once while the word at +4 is zero. */
struct Pending {
  char unk_00[4];
  int unk_04;
  char unk_08[0xc];
  void (*callback)();
};

void FUN_0889b6a0(struct Pending *self)
{
  if ((self->unk_04 == 0) && (self->callback != (void (*)())0x0)) {
    (*self->callback)();
    self->callback = 0;
  }
  return;
}
