/* LBPMATCH module=EBOOT.BIN start=0x08914d8c end=0x08914e44 symbol=FUN_08914d8c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern int DAT_08bef3f4;
extern int DAT_08bef3f8;
extern int DAT_08bef3fc;
extern int DAT_08bef404;
extern int DAT_08bef408;
extern int DAT_08bef40c;
extern int DAT_08bef410;
extern int DAT_08bef414;
extern int DAT_08bef418;
extern int DAT_08bef41c;
extern void FUN_08914c70();

/* Calls FUN_08914c70 once per entry of a fixed table of ten global values. */
void FUN_08914d8c(void *owner)
{
  FUN_08914c70(owner, DAT_08bef410);
  FUN_08914c70(owner, DAT_08bef3fc);
  FUN_08914c70(owner, DAT_08bef40c);
  FUN_08914c70(owner, DAT_08bef418);
  FUN_08914c70(owner, DAT_08bef41c);
  FUN_08914c70(owner, DAT_08bef414);
  FUN_08914c70(owner, DAT_08bef404);
  FUN_08914c70(owner, DAT_08bef408);
  FUN_08914c70(owner, DAT_08bef3f8);
  FUN_08914c70(owner, DAT_08bef3f4);
}
