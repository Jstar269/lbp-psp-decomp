/* LBPMATCH module=EBOOT.BIN start=0x089dd3d0 end=0x089dd3dc symbol=FUN_089dd3d0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089dd3a8 (a sibling wrapper passes 0 first). */
extern void FUN_089dd3a8(int flag, unsigned int mask);

void FUN_089dd3d0(void)
{
  FUN_089dd3a8(1, 0xffff);
}
