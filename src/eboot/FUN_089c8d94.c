/* LBPMATCH module=EBOOT.BIN start=0x089c8d94 end=0x089c8da0 symbol=FUN_089c8d94 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089c88ec (a sibling wrapper passes 0 first). */
extern void FUN_089c88ec(int flag, unsigned int mask);

void FUN_089c8d94(void)
{
  FUN_089c88ec(1, 0xffff);
}
