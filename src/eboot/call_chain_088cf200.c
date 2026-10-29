/* LBPMATCH module=EBOOT.BIN start=0x088cf200 end=0x088cf230 symbol=FUN_088cf200 lang=c99 */
/* Clone of src/eboot/call_chain_088ceb04.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern int FUN_088d7f9c();
extern void FUN_088f73dc(int);
extern void FUN_088e3c94(int, int);
extern int DAT_08beed8c;

void FUN_088cf200(void)
{
  int iVar1;

  iVar1 = FUN_088d7f9c();
  FUN_088f73dc(iVar1);
  FUN_088e3c94(DAT_08beed8c, 1);
  return;
}
