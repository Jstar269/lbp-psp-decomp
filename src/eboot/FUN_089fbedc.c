/* LBPMATCH module=EBOOT.BIN start=0x089fbedc end=0x089fbee8 symbol=FUN_089fbedc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089fbc8c (a sibling wrapper passes 1 first). */
extern void FUN_089fbc8c(int flag, unsigned int mask);

void FUN_089fbedc(void)
{
  FUN_089fbc8c(0, 0xffff);
}
