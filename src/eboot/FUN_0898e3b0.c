/* LBPMATCH module=EBOOT.BIN start=0x0898e3b0 end=0x0898e3f4 symbol=FUN_0898e3b0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Record {
  unsigned int unk_00;
  unsigned int unk_04;
  int part_08[6];                /* +0x08: initialised by FUN_08a9c014 */
  int part_20[7];                /* +0x20: initialised by FUN_08921788 */
  int part_3c[7];                /* +0x3c: initialised by FUN_08921788 */
  unsigned int unk_58;
};

extern void FUN_08921788();
extern void FUN_08a9c014();

/* Constructor: stores the first word, zeroes two others and initialises the three embedded parts. */
void FUN_0898e3b0(struct Record *self, unsigned int unk_00)
{
  self->unk_00 = unk_00;
  self->unk_04 = 0;
  FUN_08a9c014(self->part_08);
  FUN_08921788(self->part_20);
  FUN_08921788(self->part_3c);
  self->unk_58 = 0;
}
