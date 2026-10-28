/* LBPMATCH module=EBOOT.BIN start=0x08874b90 end=0x08874b9c symbol=FUN_08874b90 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088747dc (a sibling wrapper passes 1 first). */
extern void FUN_088747dc(int flag, unsigned int mask);

void FUN_08874b90(void)
{
  FUN_088747dc(0, 0xffff);
}
