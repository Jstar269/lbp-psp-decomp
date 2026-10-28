/* LBPMATCH module=EBOOT.BIN start=0x088b1b68 end=0x088b1b74 symbol=FUN_088b1b68 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088b191c (a sibling wrapper passes 1 first). */
extern void FUN_088b191c(int flag, unsigned int mask);

void FUN_088b1b68(void)
{
  FUN_088b191c(0, 0xffff);
}
