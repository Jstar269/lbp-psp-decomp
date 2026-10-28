/* LBPMATCH module=EBOOT.BIN start=0x089fbee8 end=0x089fbef4 symbol=FUN_089fbee8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089fbc8c (a sibling wrapper passes 0 first). */
extern void FUN_089fbc8c(int flag, unsigned int mask);

void FUN_089fbee8(void)
{
  FUN_089fbc8c(1, 0xffff);
}
