/* LBPMATCH module=EBOOT.BIN start=0x08a12b58 end=0x08a12b64 symbol=FUN_08a12b58 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a127bc (a sibling wrapper passes 0 first). */
extern void FUN_08a127bc(int flag, unsigned int mask);

void FUN_08a12b58(void)
{
  FUN_08a127bc(1, 0xffff);
}
