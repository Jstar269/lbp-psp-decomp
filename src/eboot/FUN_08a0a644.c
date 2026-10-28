/* LBPMATCH module=EBOOT.BIN start=0x08a0a644 end=0x08a0a650 symbol=FUN_08a0a644 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a0a3e8 (a sibling wrapper passes 0 first). */
extern void FUN_08a0a3e8(int flag, unsigned int mask);

void FUN_08a0a644(void)
{
  FUN_08a0a3e8(1, 0xffff);
}
