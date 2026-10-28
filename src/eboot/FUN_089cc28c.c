/* LBPMATCH module=EBOOT.BIN start=0x089cc28c end=0x089cc298 symbol=FUN_089cc28c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089cc034 (a sibling wrapper passes 0 first). */
extern void FUN_089cc034(int flag, unsigned int mask);

void FUN_089cc28c(void)
{
  FUN_089cc034(1, 0xffff);
}
