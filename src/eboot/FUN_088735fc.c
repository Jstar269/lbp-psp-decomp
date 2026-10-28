/* LBPMATCH module=EBOOT.BIN start=0x088735fc end=0x08873608 symbol=FUN_088735fc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08873538 (a sibling wrapper passes 1 first). */
extern void FUN_08873538(int flag, unsigned int mask);

void FUN_088735fc(void)
{
  FUN_08873538(0, 0xffff);
}
