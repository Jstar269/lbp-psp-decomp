/* LBPMATCH module=EBOOT.BIN start=0x089d8310 end=0x089d831c symbol=FUN_089d8310 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089d82e8 (a sibling wrapper passes 0 first). */
extern void FUN_089d82e8(int flag, unsigned int mask);

void FUN_089d8310(void)
{
  FUN_089d82e8(1, 0xffff);
}
