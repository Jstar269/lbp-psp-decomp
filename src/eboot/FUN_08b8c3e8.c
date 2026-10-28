/* LBPMATCH module=EBOOT.BIN start=0x08b8c3e8 end=0x08b8c3f8 symbol=FUN_08b8c3e8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
extern void *FUN_08b8c17c(char **self, int pos, int len, unsigned char *src, unsigned int count);

/* `first` and `last` are positions inside the buffer at *self; FUN_08b8c17c gets them as offset and length. */
void FUN_08b8c3e8(char **self, int first, int last, unsigned char *src, unsigned int count)
{
  FUN_08b8c17c(self, first - (int)*self, last - first, src, count);
  return;
}
