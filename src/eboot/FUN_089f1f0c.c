/* LBPMATCH module=EBOOT.BIN start=0x089f1f0c end=0x089f1f18 symbol=FUN_089f1f0c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089f1b80 (a sibling wrapper passes 0 first). */
extern void FUN_089f1b80(int flag, unsigned int mask);

void FUN_089f1f0c(void)
{
  FUN_089f1b80(1, 0xffff);
}
