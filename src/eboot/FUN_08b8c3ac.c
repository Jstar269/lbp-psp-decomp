/* LBPMATCH module=EBOOT.BIN start=0x08b8c3ac end=0x08b8c3c0 symbol=FUN_08b8c3ac lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int *FUN_08b8c17c();

/* Replaces the range [first, last) of the sequence at *seq with the range [src_begin, src_end):
   positions are passed on as offsets from the start of the sequence. */
void FUN_08b8c3ac(char **seq,char *first,char *last,char *src_begin,char *src_end)
{
  FUN_08b8c17c(seq,first - *seq,last - first,src_begin,src_end - src_begin);
  return;
}
