/* LBPMATCH module=EBOOT.BIN start=0x08898288 end=0x08898294 symbol=FUN_08898288 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08897f08 (a sibling wrapper passes 0 first). */
extern void FUN_08897f08(int flag, unsigned int mask);

void FUN_08898288(void)
{
  FUN_08897f08(1, 0xffff);
}
