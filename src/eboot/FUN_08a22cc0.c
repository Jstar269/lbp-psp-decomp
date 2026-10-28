/* LBPMATCH module=EBOOT.BIN start=0x08a22cc0 end=0x08a22ce8 symbol=FUN_08a22cc0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_0889b58c.c (lbpclone.py tag r-rd1c): addresses substituted; exact match verified; names and types await human review. */
extern void FUN_08a22aa4();
extern void FUN_08a22b74();

/* Calls two helpers on the same object, in this order. */
void FUN_08a22cc0(void *self)
{
  FUN_08a22aa4(self);
  FUN_08a22b74(self);
  return;
}
