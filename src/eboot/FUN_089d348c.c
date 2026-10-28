/* LBPMATCH module=EBOOT.BIN start=0x089d348c end=0x089d3498 symbol=FUN_089d348c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089d3464 (a sibling wrapper passes 0 first). */
extern void FUN_089d3464(int flag, unsigned int mask);

void FUN_089d348c(void)
{
  FUN_089d3464(1, 0xffff);
}
