/* LBPMATCH module=EBOOT.BIN start=0x08902f30 end=0x08902f3c symbol=FUN_08902f30 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08902cd8 (a sibling wrapper passes 0 first). */
extern void FUN_08902cd8(int flag, unsigned int mask);

void FUN_08902f30(void)
{
  FUN_08902cd8(1, 0xffff);
}
