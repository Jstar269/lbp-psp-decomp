/* LBPMATCH module=EBOOT.BIN start=0x089cf8ac end=0x089cf8b8 symbol=FUN_089cf8ac lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089cf884 (a sibling wrapper passes 0 first). */
extern void FUN_089cf884(int flag, unsigned int mask);

void FUN_089cf8ac(void)
{
  FUN_089cf884(1, 0xffff);
}
