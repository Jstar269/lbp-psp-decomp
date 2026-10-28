/* LBPMATCH module=EBOOT.BIN start=0x0880540c end=0x08805418 symbol=FUN_0880540c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088051b4 (a sibling wrapper passes 0 first). */
extern void FUN_088051b4(int flag, unsigned int mask);

void FUN_0880540c(void)
{
  FUN_088051b4(1, 0xffff);
}
