/* LBPMATCH module=EBOOT.BIN start=0x088fd4a4 end=0x088fd4b0 symbol=FUN_088fd4a4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088fd258 (a sibling wrapper passes 1 first). */
extern void FUN_088fd258(int flag, unsigned int mask);

void FUN_088fd4a4(void)
{
  FUN_088fd258(0, 0xffff);
}
