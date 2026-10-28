/* LBPMATCH module=EBOOT.BIN start=0x08a6cefc end=0x08a6cf08 symbol=FUN_08a6cefc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a6cca0 (a sibling wrapper passes 0 first). */
extern void FUN_08a6cca0(int flag, unsigned int mask);

void FUN_08a6cefc(void)
{
  FUN_08a6cca0(1, 0xffff);
}
