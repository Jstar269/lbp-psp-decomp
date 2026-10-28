/* LBPMATCH module=EBOOT.BIN start=0x08957e0c end=0x08957e40 symbol=FUN_08957e0c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb7ef8[];
extern void FUN_08950404(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08957e0c(void **self)
{
    *self = DAT_08bb7ef8;
    FUN_08950404(self);
    FUN_08a9e0cc(self);
}
