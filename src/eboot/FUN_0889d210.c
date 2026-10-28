/* LBPMATCH module=EBOOT.BIN start=0x0889d210 end=0x0889d240 symbol=FUN_0889d210 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  int unk_00;
  int unk_04;
  int unk_08;
  int unk_0c;
  int unk_10;
  unsigned char unk_14;          /* low byte of the word at +0x14 */
};

/* True when the words at +0 and +8 are non-zero and the byte at +0x14 is non-zero. */
unsigned int FUN_0889d210(struct Object *self)
{
  unsigned int result;

  result = 0;
  if (self->unk_00 != 0) {
    result = 1;
    if (self->unk_08 == 0 || self->unk_14 == 0) {
      result = 0;
    }
  }
  return result;
}
