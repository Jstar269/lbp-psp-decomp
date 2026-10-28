/* LBPMATCH module=EBOOT.BIN start=0x08902544 end=0x08902550 symbol=FUN_08902544 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089022f8 (a sibling wrapper passes 1 first). */
extern void FUN_089022f8(int flag, unsigned int mask);

void FUN_08902544(void)
{
  FUN_089022f8(0, 0xffff);
}
