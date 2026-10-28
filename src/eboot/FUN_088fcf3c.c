/* LBPMATCH module=EBOOT.BIN start=0x088fcf3c end=0x088fcf48 symbol=FUN_088fcf3c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088fccf0 (a sibling wrapper passes 1 first). */
extern void FUN_088fccf0(int flag, unsigned int mask);

void FUN_088fcf3c(void)
{
  FUN_088fccf0(0, 0xffff);
}
