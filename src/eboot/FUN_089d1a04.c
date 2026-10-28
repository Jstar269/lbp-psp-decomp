/* LBPMATCH module=EBOOT.BIN start=0x089d1a04 end=0x089d1a10 symbol=FUN_089d1a04 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089d19dc (a sibling wrapper passes 0 first). */
extern void FUN_089d19dc(int flag, unsigned int mask);

void FUN_089d1a04(void)
{
  FUN_089d19dc(1, 0xffff);
}
