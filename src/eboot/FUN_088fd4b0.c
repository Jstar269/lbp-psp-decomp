/* LBPMATCH module=EBOOT.BIN start=0x088fd4b0 end=0x088fd4bc symbol=FUN_088fd4b0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088fd258 (a sibling wrapper passes 0 first). */
extern void FUN_088fd258(int flag, unsigned int mask);

void FUN_088fd4b0(void)
{
  FUN_088fd258(1, 0xffff);
}
