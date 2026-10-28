/* LBPMATCH module=EBOOT.BIN start=0x08a70fd0 end=0x08a71010 symbol=FUN_08a70fd0 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct VObject {
  int (**vtable)();
};

extern unsigned int *FUN_08a10f1c();

/* True when virtual slot 37 differs from the second word of FUN_08a10f1c()'s result. */
_Bool FUN_08a70fd0(struct VObject *self)
{
  int value;
  unsigned int *other;

  value = self->vtable[37](self);
  other = FUN_08a10f1c();
  return value != other[1];
}
