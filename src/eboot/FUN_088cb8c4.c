/* LBPMATCH module=EBOOT.BIN start=0x088cb8c4 end=0x088cb8d0 symbol=FUN_088cb8c4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088cb800 (a sibling wrapper passes 1 first). */
extern void FUN_088cb800(int flag, unsigned int mask);

void FUN_088cb8c4(void)
{
  FUN_088cb800(0, 0xffff);
}
