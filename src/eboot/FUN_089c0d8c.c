/* LBPMATCH module=EBOOT.BIN start=0x089c0d8c end=0x089c0d94 symbol=FUN_089c0d8c lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_0894a860.c (lbpclone.py tag r-rd3a): addresses substituted; exact match verified; names and types await human review. */
extern int FUN_089cfa5c();

/* Object whose +8 word is the handle forwarded to FUN_089cfa5c. */
struct HandleOwner {
  unsigned char unk_00[8];
  int handle;   /* +8 */
};

void FUN_089c0d8c(struct HandleOwner *self, int arg)
{
  FUN_089cfa5c(self->handle, arg);
}
