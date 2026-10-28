/* LBPMATCH module=EBOOT.BIN start=0x088b1b74 end=0x088b1b80 symbol=FUN_088b1b74 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088b191c (a sibling wrapper passes 0 first). */
extern void FUN_088b191c(int flag, unsigned int mask);

void FUN_088b1b74(void)
{
  FUN_088b191c(1, 0xffff);
}
