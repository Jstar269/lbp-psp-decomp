/* LBPMATCH module=EBOOT.BIN start=0x088ae7b4 end=0x088ae7c0 symbol=FUN_088ae7b4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088ae78c (a sibling wrapper passes 0 first). */
extern void FUN_088ae78c(int flag, unsigned int mask);

void FUN_088ae7b4(void)
{
  FUN_088ae78c(1, 0xffff);
}
