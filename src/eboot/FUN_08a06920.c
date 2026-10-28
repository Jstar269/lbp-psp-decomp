/* LBPMATCH module=EBOOT.BIN start=0x08a06920 end=0x08a0694c symbol=FUN_08a06920 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int FUN_08a066cc();

unsigned char FUN_08a06920(int a,int *b,unsigned char flag)
{
  int result;
  int scratch [4];

  result = FUN_08a066cc(a,b,scratch,scratch,flag);
  return result != 0;
}
