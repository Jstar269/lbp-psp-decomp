/* LBPMATCH module=EBOOT.BIN start=0x089ea7c4 end=0x089ea7d0 symbol=FUN_089ea7c4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089ea798 (a sibling wrapper passes 0 first). */
extern void FUN_089ea798(int flag, unsigned int mask);

void FUN_089ea7c4(void)
{
  FUN_089ea798(1, 0xffff);
}
