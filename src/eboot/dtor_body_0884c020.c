/* LBPMATCH module=EBOOT.BIN start=0x0884c020 end=0x0884c054 symbol=FUN_0884c020 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08baed70[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0884c020(void **self)
{
    *self = DAT_08baed70;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
