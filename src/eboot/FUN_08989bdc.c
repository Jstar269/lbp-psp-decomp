/* LBPMATCH module=EBOOT.BIN start=0x08989bdc end=0x08989be8 symbol=FUN_08989bdc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08989984 (a sibling wrapper passes 0 first). */
extern void FUN_08989984(int flag, unsigned int mask);

void FUN_08989bdc(void)
{
  FUN_08989984(1, 0xffff);
}
