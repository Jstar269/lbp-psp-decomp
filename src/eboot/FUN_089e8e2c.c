/* LBPMATCH module=EBOOT.BIN start=0x089e8e2c end=0x089e8e38 symbol=FUN_089e8e2c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089e8e04 (a sibling wrapper passes 0 first). */
extern void FUN_089e8e04(int flag, unsigned int mask);

void FUN_089e8e2c(void)
{
  FUN_089e8e04(1, 0xffff);
}
