/* LBPMATCH module=EBOOT.BIN start=0x08902550 end=0x0890255c symbol=FUN_08902550 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089022f8 (a sibling wrapper passes 0 first). */
extern void FUN_089022f8(int flag, unsigned int mask);

void FUN_08902550(void)
{
  FUN_089022f8(1, 0xffff);
}
