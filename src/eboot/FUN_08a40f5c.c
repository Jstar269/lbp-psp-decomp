/* LBPMATCH module=EBOOT.BIN start=0x08a40f5c end=0x08a40fe4 symbol=FUN_08a40f5c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern void FUN_088050b8();

typedef struct Holder {
  char pad_00[0xc0];
  void *unk_c0;   /* the four members are cleared and then passed to FUN_088050b8 if they were set */
  void *unk_c4;
  void *unk_c8;
  void *unk_cc;
} Holder;

void FUN_08a40f5c(Holder *self)
{
  void *old;

  old = self->unk_c0;
  self->unk_c0 = 0;
  if (old != 0) {
    FUN_088050b8(old);
  }
  old = self->unk_c4;
  self->unk_c4 = 0;
  if (old != 0) {
    FUN_088050b8(old);
  }
  old = self->unk_c8;
  self->unk_c8 = 0;
  if (old != 0) {
    FUN_088050b8(old);
  }
  old = self->unk_cc;
  self->unk_cc = 0;
  if (old != 0) {
    FUN_088050b8(old);
    return;
  }
  return;
}
