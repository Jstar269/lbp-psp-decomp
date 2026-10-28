/* LBPMATCH module=EBOOT.BIN start=0x08a76ddc end=0x08a76de8 symbol=FUN_08a76ddc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a76b80 (a sibling wrapper passes 0 first). */
extern void FUN_08a76b80(int flag, unsigned int mask);

void FUN_08a76ddc(void)
{
  FUN_08a76b80(1, 0xffff);
}
