/* LBPMATCH module=EBOOT.BIN start=0x089d1648 end=0x089d1654 symbol=FUN_089d1648 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089d15dc (a sibling wrapper passes 0 first). */
extern void FUN_089d15dc(int flag, unsigned int mask);

void FUN_089d1648(void)
{
  FUN_089d15dc(1, 0xffff);
}
