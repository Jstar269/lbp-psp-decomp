/* LBPMATCH module=EBOOT.BIN start=0x08891a9c end=0x08891aa8 symbol=FUN_08891a9c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088919c8 (a sibling wrapper passes 1 first). */
extern void FUN_088919c8(int flag, unsigned int mask);

void FUN_08891a9c(void)
{
  FUN_088919c8(0, 0xffff);
}
