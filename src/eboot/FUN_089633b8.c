/* LBPMATCH module=EBOOT.BIN start=0x089633b8 end=0x089633c4 symbol=FUN_089633b8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08962e88 (a sibling wrapper passes 1 first). */
extern void FUN_08962e88(int flag, unsigned int mask);

void FUN_089633b8(void)
{
  FUN_08962e88(0, 0xffff);
}
