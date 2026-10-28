/* LBPMATCH module=EBOOT.BIN start=0x0894c31c end=0x0894c350 symbol=FUN_0894c31c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb7838[];
extern void FUN_08950404(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0894c31c(void **self)
{
    *self = DAT_08bb7838;
    FUN_08950404(self);
    FUN_08a9e0cc(self);
}
