/* LBPMATCH module=EBOOT.BIN start=0x0887886c end=0x08878878 symbol=FUN_0887886c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088787b4 (a sibling wrapper passes 0 first). */
extern void FUN_088787b4(int flag, unsigned int mask);

void FUN_0887886c(void)
{
  FUN_088787b4(1, 0xffff);
}
