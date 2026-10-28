/* LBPMATCH module=EBOOT.BIN start=0x08a815a8 end=0x08a815b4 symbol=FUN_08a815a8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a8134c (a sibling wrapper passes 0 first). */
extern void FUN_08a8134c(int flag, unsigned int mask);

void FUN_08a815a8(void)
{
  FUN_08a8134c(1, 0xffff);
}
