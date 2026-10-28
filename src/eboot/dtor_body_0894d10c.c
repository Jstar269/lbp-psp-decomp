/* LBPMATCH module=EBOOT.BIN start=0x0894d10c end=0x0894d140 symbol=FUN_0894d10c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb7a88[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0894d10c(void **self)
{
    *self = DAT_08bb7a88;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
