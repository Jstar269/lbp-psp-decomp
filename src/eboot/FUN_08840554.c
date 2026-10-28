/* LBPMATCH module=EBOOT.BIN start=0x08840554 end=0x08840560 symbol=FUN_08840554 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0884034c (a sibling wrapper passes 1 first). */
extern void FUN_0884034c(int flag, unsigned int mask);

void FUN_08840554(void)
{
  FUN_0884034c(0, 0xffff);
}
