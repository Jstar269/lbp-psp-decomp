/* LBPMATCH module=EBOOT.BIN start=0x0889827c end=0x08898288 symbol=FUN_0889827c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08897f08 (a sibling wrapper passes 1 first). */
extern void FUN_08897f08(int flag, unsigned int mask);

void FUN_0889827c(void)
{
  FUN_08897f08(0, 0xffff);
}
