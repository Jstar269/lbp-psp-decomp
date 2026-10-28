/* LBPMATCH module=EBOOT.BIN start=0x088f8620 end=0x088f862c symbol=FUN_088f8620 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088f80e4 (a sibling wrapper passes 0 first). */
extern void FUN_088f80e4(int flag, unsigned int mask);

void FUN_088f8620(void)
{
  FUN_088f80e4(1, 0xffff);
}
