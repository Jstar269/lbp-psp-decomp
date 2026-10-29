/* LBPMATCH module=EBOOT.BIN start=0x088ceb04 end=0x088ceb34 symbol=FUN_088ceb04 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern int FUN_088d7f9c();
extern void FUN_088f73dc(int);
extern void FUN_088e3c44(int, int);
extern int DAT_08beed8c;

void FUN_088ceb04(void)
{
  int iVar1;

  iVar1 = FUN_088d7f9c();
  FUN_088f73dc(iVar1);
  FUN_088e3c44(DAT_08beed8c, 1);
  return;
}
