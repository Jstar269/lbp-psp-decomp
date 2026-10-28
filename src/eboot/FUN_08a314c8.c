/* LBPMATCH module=EBOOT.BIN start=0x08a314c8 end=0x08a314d4 symbol=FUN_08a314c8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a3149c (a sibling wrapper passes 0 first). */
extern void FUN_08a3149c(int flag, unsigned int mask);

void FUN_08a314c8(void)
{
  FUN_08a3149c(1, 0xffff);
}
