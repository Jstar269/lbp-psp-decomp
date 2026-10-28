/* LBPMATCH module=EBOOT.BIN start=0x089593a4 end=0x089593e8 symbol=FUN_089593a4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Source {
  unsigned int (**vtable)();
};

struct Probe {
  char unk_00[4];
  struct Source *source;         /* +4 */
  int value;                     /* +8 */
};

/* Compares value - 4000 (unsigned) with what virtual slot 13 of the source returns for (0xf, 0xffff0000). */
_Bool FUN_089593a4(struct Probe *self)
{
  unsigned int result;

  result = self->source->vtable[13](self->source, 0xf, 0xffff0000);
  return self->value - 4000U < result;
}
