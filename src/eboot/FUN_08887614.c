/* LBPMATCH module=EBOOT.BIN start=0x08887614 end=0x08887624 symbol=FUN_08887614 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_088b6084.c (lbpclone.py tag r-rd2b): addresses substituted; exact match verified; names and types await human review. */
extern unsigned char DAT_08bee09c;   /* one-byte flag, set here and never cleared by this function */

/* Raises the DAT_08bee09c flag. */
void FUN_08887614(void)
{
  DAT_08bee09c = 1;
}
