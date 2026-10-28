/* LBPMATCH module=EBOOT.BIN start=0x08a8e3d8 end=0x08a8e400 symbol=FUN_08a8e3d8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
extern unsigned int *FUN_08a8e360(void *container, unsigned int *key);

/* Looks `key` up in the container embedded at +4 and returns the word FUN_08a8e360 points at. */
unsigned int FUN_08a8e3d8(char *self, unsigned int key)
{
  unsigned int key_copy[4];
  unsigned int *slot;

  key_copy[0] = key;
  slot = FUN_08a8e360(self + 4, key_copy);
  return *slot;
}
