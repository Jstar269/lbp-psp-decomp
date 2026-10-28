/* LBPMATCH module=EBOOT.BIN start=0x0884bfdc end=0x0884c010 symbol=FUN_0884bfdc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08baee28[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0884bfdc(void **self)
{
    *self = DAT_08baee28;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
