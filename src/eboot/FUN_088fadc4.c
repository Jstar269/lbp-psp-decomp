/* LBPMATCH module=EBOOT.BIN start=0x088fadc4 end=0x088fadd0 symbol=FUN_088fadc4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088fab78 (a sibling wrapper passes 1 first). */
extern void FUN_088fab78(int flag, unsigned int mask);

void FUN_088fadc4(void)
{
  FUN_088fab78(0, 0xffff);
}
