/* LBPMATCH module=EBOOT.BIN start=0x08a65924 end=0x08a65930 symbol=FUN_08a65924 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a656c8 (a sibling wrapper passes 0 first). */
extern void FUN_08a656c8(int flag, unsigned int mask);

void FUN_08a65924(void)
{
  FUN_08a656c8(1, 0xffff);
}
