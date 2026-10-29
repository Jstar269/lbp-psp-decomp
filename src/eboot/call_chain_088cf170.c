/* LBPMATCH module=EBOOT.BIN start=0x088cf170 end=0x088cf1a0 symbol=FUN_088cf170 lang=c99 */
/* Clone of src/eboot/call_chain_088ceb04.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern int FUN_088d7f9c();
extern void FUN_088f73dc(int);
extern void FUN_088e4208(int, int);
extern int DAT_08beed8c;

void FUN_088cf170(void)
{
  int iVar1;

  iVar1 = FUN_088d7f9c();
  FUN_088f73dc(iVar1);
  FUN_088e4208(DAT_08beed8c, 1);
  return;
}
