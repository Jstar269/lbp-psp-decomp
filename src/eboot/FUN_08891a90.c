/* LBPMATCH module=EBOOT.BIN start=0x08891a90 end=0x08891a9c symbol=FUN_08891a90 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088919c8 (a sibling wrapper passes 0 first). */
extern void FUN_088919c8(int flag, unsigned int mask);

void FUN_08891a90(void)
{
  FUN_088919c8(1, 0xffff);
}
