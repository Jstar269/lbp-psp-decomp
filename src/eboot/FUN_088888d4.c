/* LBPMATCH module=EBOOT.BIN start=0x088888d4 end=0x088888e0 symbol=FUN_088888d4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0888880c (a sibling wrapper passes 0 first). */
extern void FUN_0888880c(int flag, unsigned int mask);

void FUN_088888d4(void)
{
  FUN_0888880c(1, 0xffff);
}
