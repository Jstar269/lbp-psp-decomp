/* LBPMATCH module=EBOOT.BIN start=0x088888e0 end=0x088888ec symbol=FUN_088888e0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0888880c (a sibling wrapper passes 1 first). */
extern void FUN_0888880c(int flag, unsigned int mask);

void FUN_088888e0(void)
{
  FUN_0888880c(0, 0xffff);
}
