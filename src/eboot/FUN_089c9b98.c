/* LBPMATCH module=EBOOT.BIN start=0x089c9b98 end=0x089c9ba4 symbol=FUN_089c9b98 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089c9b2c (a sibling wrapper passes 0 first). */
extern void FUN_089c9b2c(int flag, unsigned int mask);

void FUN_089c9b98(void)
{
  FUN_089c9b2c(1, 0xffff);
}
