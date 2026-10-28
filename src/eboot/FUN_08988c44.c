/* LBPMATCH module=EBOOT.BIN start=0x08988c44 end=0x08988c50 symbol=FUN_08988c44 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089889ec (a sibling wrapper passes 0 first). */
extern void FUN_089889ec(int flag, unsigned int mask);

void FUN_08988c44(void)
{
  FUN_089889ec(1, 0xffff);
}
