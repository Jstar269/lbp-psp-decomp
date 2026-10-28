/* LBPMATCH module=EBOOT.BIN start=0x0896b300 end=0x0896b30c symbol=FUN_0896b300 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0896b2d8 (a sibling wrapper passes 0 first). */
extern void FUN_0896b2d8(int flag, unsigned int mask);

void FUN_0896b300(void)
{
  FUN_0896b2d8(1, 0xffff);
}
