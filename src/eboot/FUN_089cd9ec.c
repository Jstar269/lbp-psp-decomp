/* LBPMATCH module=EBOOT.BIN start=0x089cd9ec end=0x089cd9f8 symbol=FUN_089cd9ec lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089cd9c4 (a sibling wrapper passes 0 first). */
extern void FUN_089cd9c4(int flag, unsigned int mask);

void FUN_089cd9ec(void)
{
  FUN_089cd9c4(1, 0xffff);
}
