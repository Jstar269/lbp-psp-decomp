/* LBPMATCH module=EBOOT.BIN start=0x088903f8 end=0x08890404 symbol=FUN_088903f8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08890118 (a sibling wrapper passes 1 first). */
extern void FUN_08890118(int flag, unsigned int mask);

void FUN_088903f8(void)
{
  FUN_08890118(0, 0xffff);
}
