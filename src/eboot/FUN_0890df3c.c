/* LBPMATCH module=EBOOT.BIN start=0x0890df3c end=0x0890df48 symbol=FUN_0890df3c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0890dca8 (a sibling wrapper passes 1 first). */
extern void FUN_0890dca8(int flag, unsigned int mask);

void FUN_0890df3c(void)
{
  FUN_0890dca8(0, 0xffff);
}
