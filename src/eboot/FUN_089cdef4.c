/* LBPMATCH module=EBOOT.BIN start=0x089cdef4 end=0x089cdf50 symbol=FUN_089cdef4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern int DAT_08bf0380;
extern void FUN_088050b8();
extern void FUN_089e15dc();

struct OwnerRec {
  unsigned char unk_00[0x1c];
  int unk_1c;
  int *owned;              /* +0x20: released through FUN_088050b8 and cleared */
  unsigned int unk_24;
};

void FUN_089cdef4(struct OwnerRec *self, unsigned int value)
{
  int *old;

  FUN_089e15dc(DAT_08bf0380, &self->owned, self->unk_1c);
  old = self->owned;
  self->owned = 0;
  if (old != 0) {
    FUN_088050b8(old);
  }
  self->unk_24 = value;
}
