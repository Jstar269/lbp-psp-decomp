/* LBPMATCH module=EBOOT.BIN start=0x089220fc end=0x08922108 symbol=FUN_089220fc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08921e2c (a sibling wrapper passes 1 first). */
extern void FUN_08921e2c(int flag, unsigned int mask);

void FUN_089220fc(void)
{
  FUN_08921e2c(0, 0xffff);
}
