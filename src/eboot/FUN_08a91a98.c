/* LBPMATCH module=EBOOT.BIN start=0x08a91a98 end=0x08a91aa0 symbol=FUN_08a91a98 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a3fe70 with no arguments. */
extern void FUN_08a3fe70(void);

void FUN_08a91a98(void)
{
  FUN_08a3fe70();
}
