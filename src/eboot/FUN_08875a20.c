/* LBPMATCH module=EBOOT.BIN start=0x08875a20 end=0x08875a2c symbol=FUN_08875a20 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08875958 (a sibling wrapper passes 0 first). */
extern void FUN_08875958(int flag, unsigned int mask);

void FUN_08875a20(void)
{
  FUN_08875958(1, 0xffff);
}
