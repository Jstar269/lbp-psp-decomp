/* LBPMATCH module=EBOOT.BIN start=0x08849fbc end=0x08849fc8 symbol=FUN_08849fbc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08849ee8 (a sibling wrapper passes 1 first). */
extern void FUN_08849ee8(int flag, unsigned int mask);

void FUN_08849fbc(void)
{
  FUN_08849ee8(0, 0xffff);
}
