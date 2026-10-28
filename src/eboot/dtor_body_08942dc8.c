/* LBPMATCH module=EBOOT.BIN start=0x08942dc8 end=0x08942dfc symbol=FUN_08942dc8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb75a8[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08942dc8(void **self)
{
    *self = DAT_08bb75a8;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
