/* LBPMATCH module=EBOOT.BIN start=0x0880b080 end=0x0880b090 symbol=FUN_0880b080 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_088b6084.c (lbpclone.py tag r-rd2b): addresses substituted; exact match verified; names and types await human review. */
extern unsigned char DAT_08be8514;   /* one-byte flag, set here and never cleared by this function */

/* Raises the DAT_08be8514 flag. */
void FUN_0880b080(void)
{
  DAT_08be8514 = 1;
}
