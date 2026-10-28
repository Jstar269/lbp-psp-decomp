/* LBPMATCH module=EBOOT.BIN start=0x088fadd0 end=0x088faddc symbol=FUN_088fadd0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088fab78 (a sibling wrapper passes 0 first). */
extern void FUN_088fab78(int flag, unsigned int mask);

void FUN_088fadd0(void)
{
  FUN_088fab78(1, 0xffff);
}
