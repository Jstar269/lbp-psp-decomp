/* LBPMATCH module=EBOOT.BIN start=0x08914f68 end=0x089150b4 symbol=FUN_08914f68 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g9); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Calls FUN_08914e94(self, <global>) for each of eleven globals in turn and passes its result to FUN_08aca008 with 1. */
extern unsigned int DAT_08bef3f4;
extern unsigned int DAT_08bef3f8;
extern unsigned int DAT_08bef3fc;
extern unsigned int DAT_08bef400;
extern unsigned int DAT_08bef404;
extern unsigned int DAT_08bef408;
extern unsigned int DAT_08bef40c;
extern unsigned int DAT_08bef410;
extern unsigned int DAT_08bef414;
extern unsigned int DAT_08bef418;
extern unsigned int DAT_08bef41c;
extern int *FUN_08914e94(void *self, unsigned int value);
extern void FUN_08aca008(int *object, int flag);

void FUN_08914f68(void *self)
{
  int *object;

  object = FUN_08914e94(self, DAT_08bef41c);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef418);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef414);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef410);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef40c);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef408);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef3f8);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef404);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef400);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef3fc);
  FUN_08aca008(object, 1);
  object = FUN_08914e94(self, DAT_08bef3f4);
  FUN_08aca008(object, 1);
}
