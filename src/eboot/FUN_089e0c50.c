/* LBPMATCH module=EBOOT.BIN start=0x089e0c50 end=0x089e0c5c symbol=FUN_089e0c50 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089e0c28 (a sibling wrapper passes 0 first). */
extern void FUN_089e0c28(int flag, unsigned int mask);

void FUN_089e0c50(void)
{
  FUN_089e0c28(1, 0xffff);
}
