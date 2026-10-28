/* LBPMATCH module=EBOOT.BIN start=0x088d4d00 end=0x088d4de8 symbol=FUN_088d4d00 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
extern void *DAT_08beee0c;     /* global object pointer, same one FUN_088cf348 uses */
extern void FUN_088d4ae0();
extern void FUN_088f14a4();
extern void FUN_088f18f4();
extern void FUN_08a9bff8();    /* releases the buffer a FUN_08a9c014 temporary holds at +8 */
extern void FUN_08a9c014();    /* constructs the 8-word temporary */

/* For selectors 0, 1, 2 and 4, fills a fresh temporary from `owner` and hands it to the global
   object; selector 4 goes through a different entry point (FUN_088f18f4, no selector argument). */
void FUN_088d4d00(void *owner)
{
  unsigned int temp[8];

  FUN_08a9c014(temp);
  FUN_088d4ae0(owner, temp, 0);
  FUN_088f14a4(DAT_08beee0c, temp, 0);
  FUN_08a9bff8(temp);

  FUN_08a9c014(temp);
  FUN_088d4ae0(owner, temp, 1);
  FUN_088f14a4(DAT_08beee0c, temp, 1);
  FUN_08a9bff8(temp);

  FUN_08a9c014(temp);
  FUN_088d4ae0(owner, temp, 2);
  FUN_088f14a4(DAT_08beee0c, temp, 2);
  FUN_08a9bff8(temp);

  FUN_08a9c014(temp);
  FUN_088d4ae0(owner, temp, 4);
  FUN_088f18f4(DAT_08beee0c, temp);
  FUN_08a9bff8(temp);
}
