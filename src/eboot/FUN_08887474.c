/* LBPMATCH module=EBOOT.BIN start=0x08887474 end=0x08887480 symbol=FUN_08887474 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088873a0 (a sibling wrapper passes 1 first). */
extern void FUN_088873a0(int flag, unsigned int mask);

void FUN_08887474(void)
{
  FUN_088873a0(0, 0xffff);
}
