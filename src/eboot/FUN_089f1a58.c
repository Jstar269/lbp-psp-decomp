/* LBPMATCH module=EBOOT.BIN start=0x089f1a58 end=0x089f1a64 symbol=FUN_089f1a58 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089f1a2c (a sibling wrapper passes 0 first). */
extern void FUN_089f1a2c(int flag, unsigned int mask);

void FUN_089f1a58(void)
{
  FUN_089f1a2c(1, 0xffff);
}
