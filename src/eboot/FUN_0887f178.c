/* LBPMATCH module=EBOOT.BIN start=0x0887f178 end=0x0887f1b4 symbol=FUN_0887f178 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Object {
  unsigned char unk_00[0x9d];
  unsigned char byte_a;          /* +0x9d: first byte of a table with a 0x30-byte stride */
  unsigned char unk_9e[0x507];
  unsigned char byte_b;          /* +0x5a5: first byte of a table with a 0x34-byte stride */
};

/* Reads one byte of table B (flag set) or table A (flag clear) for the given entry. */
unsigned char FUN_0887f178(struct Object *self, int index, unsigned char use_b)
{
  if (use_b != 0) {
    return (&self->byte_b)[index * 0x34];
  }
  return (&self->byte_a)[index * 0x30];
}
