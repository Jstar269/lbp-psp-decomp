/* LBPMATCH module=EBOOT.BIN start=0x0887d76c end=0x0887d850 symbol=FUN_0887d76c lang=c99 cc=gcc402x-Os rodata=0x08bb0918 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int FUN_08873774();
extern int FUN_08873934();
extern int FUN_08ba0e8c();

/* Writes both strings and then a fixed 18-byte marker string, through FUN_08873774 when flag is set and
   FUN_08873934 otherwise (the two sequences are identical). FUN_08ba0e8c gives each string's length. */
void FUN_0887d76c(int stream, unsigned char flag, char *str_a, char *str_b)
{
  unsigned int len;

  if (flag != 0) {
    len = FUN_08ba0e8c(str_a);
    FUN_08873774(stream,str_a,len);
    len = FUN_08ba0e8c(str_b);
    FUN_08873774(stream,str_b,len);
    FUN_08873774(stream,"!?/*hjk7duOZ1f@daX",0x12);
    return;
  }
  len = FUN_08ba0e8c(str_a);
  FUN_08873934(stream,str_a,len);
  len = FUN_08ba0e8c(str_b);
  FUN_08873934(stream,str_b,len);
  FUN_08873934(stream,"!?/*hjk7duOZ1f@daX",0x12);
  return;
}
