/* LBPMATCH module=EBOOT.BIN start=0x0884ba94 end=0x0884baa0 symbol=FUN_0884ba94 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0884b9cc (a sibling wrapper passes 0 first). */
extern void FUN_0884b9cc(int flag, unsigned int mask);

void FUN_0884ba94(void)
{
  FUN_0884b9cc(1, 0xffff);
}
