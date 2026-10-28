/* LBPMATCH module=EBOOT.BIN start=0x08a95edc end=0x08a95ee8 symbol=FUN_08a95edc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08a95c8c (a sibling wrapper passes 1 first). */
extern void FUN_08a95c8c(int flag, unsigned int mask);

void FUN_08a95edc(void)
{
  FUN_08a95c8c(0, 0xffff);
}
