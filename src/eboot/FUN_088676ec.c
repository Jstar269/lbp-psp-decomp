/* LBPMATCH module=EBOOT.BIN start=0x088676ec end=0x08867714 symbol=FUN_088676ec lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  char unk_00[0x1b0];
  int unk_1b0;
  char unk_1b4[0x138];
  int unk_2ec;
};

/* True when the word at +0x2ec is non-zero and the word at +0x1b0 is not 3. */
unsigned int FUN_088676ec(struct Object *self)
{
  unsigned int result;

  result = 1;
  if ((self->unk_2ec == 0) || (self->unk_1b0 == 3)) {
    result = 0;
  }
  return result;
}
