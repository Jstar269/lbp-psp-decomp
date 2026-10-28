/* LBPMATCH module=EBOOT.BIN start=0x08863884 end=0x088638b8 symbol=FUN_08863884 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bafd98[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08863884(void **self)
{
    *self = DAT_08bafd98;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
