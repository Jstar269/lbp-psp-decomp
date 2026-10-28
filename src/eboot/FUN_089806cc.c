/* LBPMATCH module=EBOOT.BIN start=0x089806cc end=0x089806d8 symbol=FUN_089806cc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089803f0 (a sibling wrapper passes 0 first). */
extern void FUN_089803f0(int flag, unsigned int mask);

void FUN_089806cc(void)
{
  FUN_089803f0(1, 0xffff);
}
