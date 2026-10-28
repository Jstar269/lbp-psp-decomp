/* LBPMATCH module=EBOOT.BIN start=0x088bbf60 end=0x088bbf6c symbol=FUN_088bbf60 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088bbb4c (a sibling wrapper passes 0 first). */
extern void FUN_088bbb4c(int flag, unsigned int mask);

void FUN_088bbf60(void)
{
  FUN_088bbb4c(1, 0xffff);
}
