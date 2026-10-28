/* LBPMATCH module=EBOOT.BIN start=0x08992168 end=0x08992174 symbol=FUN_08992168 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08991f1c (a sibling wrapper passes 1 first). */
extern void FUN_08991f1c(int flag, unsigned int mask);

void FUN_08992168(void)
{
  FUN_08991f1c(0, 0xffff);
}
