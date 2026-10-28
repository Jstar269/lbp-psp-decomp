/* LBPMATCH module=EBOOT.BIN start=0x08a7fb30 end=0x08a7fb7c symbol=FUN_08a7fb30 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Owner {
  char unk_00[0x268];
  void *owned;           /* +0x268: released with FUN_088050b8, then cleared */
  char unk_26c[0x14];
  int part_280[6];       /* +0x280: handed to FUN_08a9c6b0 */
  int part_298[6];       /* +0x298: handed to FUN_08a9c6b0 */
};

extern void FUN_088050b8();
extern void FUN_08a9c6b0();

void FUN_08a7fb30(struct Owner *self)
{
  void *owned;

  owned = self->owned;
  self->owned = 0;
  if (owned != 0) {
    FUN_088050b8(owned);
  }
  FUN_08a9c6b0(self->part_280, 1);
  FUN_08a9c6b0(self->part_298, 1);
}
