/* LBPMATCH module=EBOOT.BIN start=0x088fb6a8 end=0x088fb6b4 symbol=FUN_088fb6a8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088fb45c (a sibling wrapper passes 1 first). */
extern void FUN_088fb45c(int flag, unsigned int mask);

void FUN_088fb6a8(void)
{
  FUN_088fb45c(0, 0xffff);
}
