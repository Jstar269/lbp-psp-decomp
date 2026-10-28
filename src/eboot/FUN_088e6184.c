/* LBPMATCH module=EBOOT.BIN start=0x088e6184 end=0x088e6190 symbol=FUN_088e6184 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08882764.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Returns the address of the global object at 0x8bb4c74 (type unknown). */
extern unsigned char DAT_08bb4c74;

unsigned char *FUN_088e6184(void)
{
  return &DAT_08bb4c74;
}
