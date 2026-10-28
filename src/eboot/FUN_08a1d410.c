/* LBPMATCH module=EBOOT.BIN start=0x08a1d410 end=0x08a1d41c symbol=FUN_08a1d410 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a1d3e4 (a sibling wrapper passes 0 first). */
extern void FUN_08a1d3e4(int flag, unsigned int mask);

void FUN_08a1d410(void)
{
  FUN_08a1d3e4(1, 0xffff);
}
