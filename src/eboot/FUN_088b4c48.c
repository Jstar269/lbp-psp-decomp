/* LBPMATCH module=EBOOT.BIN start=0x088b4c48 end=0x088b4c54 symbol=FUN_088b4c48 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08882764.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Returns the address of the global object at 0x8bb34c4 (type unknown). */
extern unsigned char DAT_08bb34c4;

unsigned char *FUN_088b4c48(void)
{
  return &DAT_08bb34c4;
}
