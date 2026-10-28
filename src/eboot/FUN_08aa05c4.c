/* LBPMATCH module=EBOOT.BIN start=0x08aa05c4 end=0x08aa05d0 symbol=FUN_08aa05c4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08aa0568 (a sibling wrapper passes 1 first). */
extern void FUN_08aa0568(int flag, unsigned int mask);

void FUN_08aa05c4(void)
{
  FUN_08aa0568(0, 0xffff);
}
