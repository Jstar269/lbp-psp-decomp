/* LBPMATCH module=EBOOT.BIN start=0x0896c33c end=0x0896c348 symbol=FUN_0896c33c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0896c314 (a sibling wrapper passes 0 first). */
extern void FUN_0896c314(int flag, unsigned int mask);

void FUN_0896c33c(void)
{
  FUN_0896c314(1, 0xffff);
}
