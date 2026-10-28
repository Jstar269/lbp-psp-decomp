/* LBPMATCH module=EBOOT.BIN start=0x088e1164 end=0x088e1170 symbol=FUN_088e1164 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088e0c34 (a sibling wrapper passes 1 first). */
extern void FUN_088e0c34(int flag, unsigned int mask);

void FUN_088e1164(void)
{
  FUN_088e0c34(0, 0xffff);
}
