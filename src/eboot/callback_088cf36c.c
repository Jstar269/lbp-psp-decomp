/* LBPMATCH module=EBOOT.BIN start=0x088cf36c end=0x088cf3d4 symbol=FUN_088cf36c lang=c99 */
/* Clone of src/eboot/callback_088cf2e0.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char *DAT_08beee0c; extern void *DAT_08beed8c; extern int FUN_088e76b4(void *,void *), FUN_088d7f9c(void); extern void FUN_088f73dc(int), FUN_088e3aec(void *,int,int); void FUN_088cf36c(void);
void FUN_088cf36c(void) { if(!FUN_088e76b4(DAT_08beee0c,FUN_088cf36c)) { FUN_088f73dc(FUN_088d7f9c()); FUN_088e3aec(DAT_08beed8c,*(int *)(DAT_08beee0c+204),1); } }
