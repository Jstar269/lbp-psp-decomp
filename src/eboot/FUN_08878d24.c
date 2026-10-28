/* LBPMATCH module=EBOOT.BIN start=0x08878d24 end=0x08878d40 symbol=FUN_08878d24 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Indexed {
  char pad[0x10];
  int index;
};

/* Takes the word at position index (counted in words from the object start) and clears it and the word two further on. */
unsigned int FUN_08878d24(struct Indexed *self)
{
  unsigned int value;
  unsigned int *entry;

  entry = (unsigned int *)(self->index * 4 + (int)self);
  value = *entry;
  entry[2] = 0;
  *entry = 0;
  return value;
}
