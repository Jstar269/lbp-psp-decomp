/* LBPMATCH module=EBOOT.BIN start=0x08a8b1c0 end=0x08a8b1cc symbol=FUN_08a8b1c0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08a8ad50 (a sibling wrapper passes 1 first). */
extern void FUN_08a8ad50(int flag, unsigned int mask);

void FUN_08a8b1c0(void)
{
  FUN_08a8ad50(0, 0xffff);
}
