/* LBPMATCH module=EBOOT.BIN start=0x088771e8 end=0x08877230 symbol=FUN_088771e8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_08a9e0c4();

struct Slot3c {
  char unk_00[0x3c];
  unsigned int buffer;
};

void FUN_088771e8(int unused,unsigned int *out,struct Slot3c *self)
{
  if (self->buffer != 0) {
    FUN_08a9e0c4(self->buffer);
  }
  self->buffer = 0;
  *out = 0;
  return;
}
