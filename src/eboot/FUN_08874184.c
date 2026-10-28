/* LBPMATCH module=EBOOT.BIN start=0x08874184 end=0x08874190 symbol=FUN_08874184 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_088740c0 (a sibling wrapper passes 1 first). */
extern void FUN_088740c0(int flag, unsigned int mask);

void FUN_08874184(void)
{
  FUN_088740c0(0, 0xffff);
}
