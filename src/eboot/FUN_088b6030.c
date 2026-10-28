/* LBPMATCH module=EBOOT.BIN start=0x088b6030 end=0x088b603c symbol=FUN_088b6030 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08882764.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Returns the address of the global object at 0x8bb361c (type unknown). */
extern unsigned char DAT_08bb361c;

unsigned char *FUN_088b6030(void)
{
  return &DAT_08bb361c;
}
