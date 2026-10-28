/* LBPMATCH module=EBOOT.BIN start=0x089acb38 end=0x089acb44 symbol=FUN_089acb38 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089acadc (a sibling wrapper passes 0 first). */
extern void FUN_089acadc(int flag, unsigned int mask);

void FUN_089acb38(void)
{
  FUN_089acadc(1, 0xffff);
}
