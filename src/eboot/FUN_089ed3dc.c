/* LBPMATCH module=EBOOT.BIN start=0x089ed3dc end=0x089ed3e8 symbol=FUN_089ed3dc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089ed308 (a sibling wrapper passes 1 first). */
extern void FUN_089ed308(int flag, unsigned int mask);

void FUN_089ed3dc(void)
{
  FUN_089ed308(0, 0xffff);
}
