/* LBPMATCH module=EBOOT.BIN start=0x089ace20 end=0x089ace2c symbol=FUN_089ace20 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089acdf8 (a sibling wrapper passes 0 first). */
extern void FUN_089acdf8(int flag, unsigned int mask);

void FUN_089ace20(void)
{
  FUN_089acdf8(1, 0xffff);
}
