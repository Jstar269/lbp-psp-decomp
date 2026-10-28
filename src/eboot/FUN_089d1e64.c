/* LBPMATCH module=EBOOT.BIN start=0x089d1e64 end=0x089d1e70 symbol=FUN_089d1e64 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089d1e3c (a sibling wrapper passes 0 first). */
extern void FUN_089d1e3c(int flag, unsigned int mask);

void FUN_089d1e64(void)
{
  FUN_089d1e3c(1, 0xffff);
}
