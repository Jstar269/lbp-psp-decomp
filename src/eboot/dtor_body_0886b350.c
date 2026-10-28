/* LBPMATCH module=EBOOT.BIN start=0x0886b350 end=0x0886b384 symbol=FUN_0886b350 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08baec60[];
extern void FUN_0885c9f8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0886b350(void **self)
{
    *self = DAT_08baec60;
    FUN_0885c9f8(self);
    FUN_08a9e0cc(self);
}
