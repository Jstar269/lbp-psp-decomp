/* LBPMATCH module=EBOOT.BIN start=0x088d2ecc end=0x088d2ed8 symbol=FUN_088d2ecc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088d29d0 (a sibling wrapper passes 0 first). */
extern void FUN_088d29d0(int flag, unsigned int mask);

void FUN_088d2ecc(void)
{
  FUN_088d29d0(1, 0xffff);
}
