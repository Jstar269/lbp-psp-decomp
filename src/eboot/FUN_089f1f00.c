/* LBPMATCH module=EBOOT.BIN start=0x089f1f00 end=0x089f1f0c symbol=FUN_089f1f00 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089f1b80 (a sibling wrapper passes 1 first). */
extern void FUN_089f1b80(int flag, unsigned int mask);

void FUN_089f1f00(void)
{
  FUN_089f1b80(0, 0xffff);
}
