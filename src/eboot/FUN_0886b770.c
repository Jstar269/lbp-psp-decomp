/* LBPMATCH module=EBOOT.BIN start=0x0886b770 end=0x0886b790 symbol=FUN_0886b770 lang=c99 cc=gcc404xs-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g14); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct ClearedObj {
  char unk_00[0x298];
  int unk_298;
};

/* Clears the word at +0x298, then calls itself with the same argument and returns that result. */
unsigned char FUN_0886b770(struct ClearedObj *self)
{
  unsigned char result;

  self->unk_298 = 0;
  result = FUN_0886b770(self);
  return result;
}
