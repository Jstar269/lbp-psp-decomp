/* LBPMATCH module=EBOOT.BIN start=0x089ab41c end=0x089ab428 symbol=FUN_089ab41c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089ab354 (a sibling wrapper passes 0 first). */
extern void FUN_089ab354(int flag, unsigned int mask);

void FUN_089ab41c(void)
{
  FUN_089ab354(1, 0xffff);
}
