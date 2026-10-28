/* LBPMATCH module=EBOOT.BIN start=0x08879418 end=0x08879424 symbol=FUN_08879418 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08878f7c (a sibling wrapper passes 1 first). */
extern void FUN_08878f7c(int flag, unsigned int mask);

void FUN_08879418(void)
{
  FUN_08878f7c(0, 0xffff);
}
