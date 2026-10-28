/* LBPMATCH module=EBOOT.BIN start=0x08b8c4ac end=0x08b8c4c4 symbol=FUN_08b8c4ac lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int *FUN_08b8c17c();

/* Text buffer header stored just before the characters: the length is the first word. */
struct TextHeader {
  unsigned int length;
  unsigned int unk_04;
  unsigned int unk_08;
};

/* Same replace as the range versions, but the source is a pointer to a buffer pointer (its length comes
   from the header in front of the characters). */
void FUN_08b8c4ac(char **seq,char *first,char *last,char **src)
{
  FUN_08b8c17c(seq,first - *seq,last - first,*src,((struct TextHeader *)*src - 1)->length);
  return;
}
