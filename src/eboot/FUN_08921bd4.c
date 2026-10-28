/* LBPMATCH module=EBOOT.BIN start=0x08921bd4 end=0x08921be0 symbol=FUN_08921bd4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08921b0c (a sibling wrapper passes 0 first). */
extern void FUN_08921b0c(int flag, unsigned int mask);

void FUN_08921bd4(void)
{
  FUN_08921b0c(1, 0xffff);
}
