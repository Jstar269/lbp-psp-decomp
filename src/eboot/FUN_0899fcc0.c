/* LBPMATCH module=EBOOT.BIN start=0x0899fcc0 end=0x0899fccc symbol=FUN_0899fcc0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0899fc54 (a sibling wrapper passes 0 first). */
extern void FUN_0899fc54(int flag, unsigned int mask);

void FUN_0899fcc0(void)
{
  FUN_0899fc54(1, 0xffff);
}
