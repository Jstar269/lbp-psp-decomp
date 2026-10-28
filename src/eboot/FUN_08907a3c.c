/* LBPMATCH module=EBOOT.BIN start=0x08907a3c end=0x08907a48 symbol=FUN_08907a3c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08907834 (a sibling wrapper passes 1 first). */
extern void FUN_08907834(int flag, unsigned int mask);

void FUN_08907a3c(void)
{
  FUN_08907834(0, 0xffff);
}
