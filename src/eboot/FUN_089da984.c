/* LBPMATCH module=EBOOT.BIN start=0x089da984 end=0x089da9ac symbol=FUN_089da984 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_0889b58c.c (lbpclone.py tag r-rd1c): addresses substituted; exact match verified; names and types await human review. */
extern void FUN_089e1388();
extern void FUN_089da888();

/* Calls two helpers on the same object, in this order. */
void FUN_089da984(void *self)
{
  FUN_089e1388(self);
  FUN_089da888(self);
  return;
}
