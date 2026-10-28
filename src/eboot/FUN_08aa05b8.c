/* LBPMATCH module=EBOOT.BIN start=0x08aa05b8 end=0x08aa05c4 symbol=FUN_08aa05b8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08aa0568 (a sibling wrapper passes 0 first). */
extern void FUN_08aa0568(int flag, unsigned int mask);

void FUN_08aa05b8(void)
{
  FUN_08aa0568(1, 0xffff);
}
