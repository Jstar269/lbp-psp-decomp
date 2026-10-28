/* LBPMATCH module=EBOOT.BIN start=0x089e9d18 end=0x089e9d24 symbol=FUN_089e9d18 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089e9998 (a sibling wrapper passes 1 first). */
extern void FUN_089e9998(int flag, unsigned int mask);

void FUN_089e9d18(void)
{
  FUN_089e9998(0, 0xffff);
}
