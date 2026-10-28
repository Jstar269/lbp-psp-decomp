/* LBPMATCH module=EBOOT.BIN start=0x08a90024 end=0x08a90030 symbol=FUN_08a90024 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08a8fdd4 (a sibling wrapper passes 1 first). */
extern void FUN_08a8fdd4(int flag, unsigned int mask);

void FUN_08a90024(void)
{
  FUN_08a8fdd4(0, 0xffff);
}
