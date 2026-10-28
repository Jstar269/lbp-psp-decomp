/* LBPMATCH module=EBOOT.BIN start=0x088d3e48 end=0x088d3e54 symbol=FUN_088d3e48 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088d3918 (a sibling wrapper passes 1 first). */
extern void FUN_088d3918(int flag, unsigned int mask);

void FUN_088d3e48(void)
{
  FUN_088d3918(0, 0xffff);
}
