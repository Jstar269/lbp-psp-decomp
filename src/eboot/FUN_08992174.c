/* LBPMATCH module=EBOOT.BIN start=0x08992174 end=0x08992180 symbol=FUN_08992174 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08991f1c (a sibling wrapper passes 0 first). */
extern void FUN_08991f1c(int flag, unsigned int mask);

void FUN_08992174(void)
{
  FUN_08991f1c(1, 0xffff);
}
