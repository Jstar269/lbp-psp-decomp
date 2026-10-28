/* LBPMATCH module=EBOOT.BIN start=0x089d2edc end=0x089d2ee8 symbol=FUN_089d2edc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089d2e70 (a sibling wrapper passes 0 first). */
extern void FUN_089d2e70(int flag, unsigned int mask);

void FUN_089d2edc(void)
{
  FUN_089d2e70(1, 0xffff);
}
