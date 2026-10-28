/* LBPMATCH module=EBOOT.BIN start=0x0888acc0 end=0x0888acf0 symbol=FUN_0888acc0 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  int unk_00;
  int state;                     /* +4 */
  char unk_08[0x50];
  int unk_58;
  char unk_5c;
  unsigned char value;           /* +0x5d */
  char unk_5e[0x476];
  int unk_4d4;
};

/* Only acts while both words at +0 and +4 are zero: stores `value`, sets state 2 and clears two words. */
void FUN_0888acc0(struct Object *self, unsigned char value)
{
  if ((self->state == 0) && (self->unk_00 == 0)) {
    self->value = value;
    self->state = 2;
    self->unk_58 = 0;
    self->unk_4d4 = 0;
  }
}
