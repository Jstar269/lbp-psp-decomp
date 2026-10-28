/* LBPMATCH module=EBOOT.BIN start=0x08913264 end=0x08913270 symbol=FUN_08913264 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0891311c (a sibling wrapper passes 0 first). */
extern void FUN_0891311c(int flag, unsigned int mask);

void FUN_08913264(void)
{
  FUN_0891311c(1, 0xffff);
}
