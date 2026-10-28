/* LBPMATCH module=EBOOT.BIN start=0x08849fb0 end=0x08849fbc symbol=FUN_08849fb0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08849ee8 (a sibling wrapper passes 0 first). */
extern void FUN_08849ee8(int flag, unsigned int mask);

void FUN_08849fb0(void)
{
  FUN_08849ee8(1, 0xffff);
}
