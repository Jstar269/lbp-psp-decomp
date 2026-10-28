/* LBPMATCH module=EBOOT.BIN start=0x089ceac8 end=0x089ceadc symbol=FUN_089ceac8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Cursor {
  char unk_00[0x18];
  unsigned int limit;            /* +0x18 */
  unsigned int position;         /* +0x1c */
};

/* position = min(value, limit) */
void FUN_089ceac8(struct Cursor *self, unsigned int value)
{
  if (self->limit <= value) {
    value = self->limit;
  }
  self->position = value;
}
