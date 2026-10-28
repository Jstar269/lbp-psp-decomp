/* LBPMATCH module=EBOOT.BIN start=0x08840560 end=0x0884056c symbol=FUN_08840560 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0884034c (a sibling wrapper passes 0 first). */
extern void FUN_0884034c(int flag, unsigned int mask);

void FUN_08840560(void)
{
  FUN_0884034c(1, 0xffff);
}
