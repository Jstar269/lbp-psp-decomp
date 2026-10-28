/* LBPMATCH module=EBOOT.BIN start=0x08a8f6a8 end=0x08a8f6b4 symbol=FUN_08a8f6a8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a8f390 (a sibling wrapper passes 0 first). */
extern void FUN_08a8f390(int flag, unsigned int mask);

void FUN_08a8f6a8(void)
{
  FUN_08a8f390(1, 0xffff);
}
