/* LBPMATCH module=EBOOT.BIN start=0x08974dec end=0x08974df8 symbol=FUN_08974dec lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08974dc4 (a sibling wrapper passes 0 first). */
extern void FUN_08974dc4(int flag, unsigned int mask);

void FUN_08974dec(void)
{
  FUN_08974dc4(1, 0xffff);
}
