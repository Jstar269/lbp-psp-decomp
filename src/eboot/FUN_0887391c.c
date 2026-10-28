/* LBPMATCH module=EBOOT.BIN start=0x0887391c end=0x08873928 symbol=FUN_0887391c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08873864 (a sibling wrapper passes 0 first). */
extern void FUN_08873864(int flag, unsigned int mask);

void FUN_0887391c(void)
{
  FUN_08873864(1, 0xffff);
}
