/* LBPMATCH module=EBOOT.BIN start=0x0887701c end=0x08877028 symbol=FUN_0887701c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08876f54 (a sibling wrapper passes 0 first). */
extern void FUN_08876f54(int flag, unsigned int mask);

void FUN_0887701c(void)
{
  FUN_08876f54(1, 0xffff);
}
