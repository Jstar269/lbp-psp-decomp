/* LBPMATCH module=EBOOT.BIN start=0x08878878 end=0x08878884 symbol=FUN_08878878 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088787b4 (a sibling wrapper passes 1 first). */
extern void FUN_088787b4(int flag, unsigned int mask);

void FUN_08878878(void)
{
  FUN_088787b4(0, 0xffff);
}
