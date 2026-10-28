/* LBPMATCH module=EBOOT.BIN start=0x089cc280 end=0x089cc28c symbol=FUN_089cc280 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089cc034 (a sibling wrapper passes 1 first). */
extern void FUN_089cc034(int flag, unsigned int mask);

void FUN_089cc280(void)
{
  FUN_089cc034(0, 0xffff);
}
