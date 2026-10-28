/* LBPMATCH module=EBOOT.BIN start=0x0885da90 end=0x0885daa0 symbol=FUN_0885da90 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0885c9f8, tail call). */
extern char DAT_08baec60[];
extern void FUN_0885c9f8(void *self);
void FUN_0885da90(void **self)
{
    *self = DAT_08baec60;
    FUN_0885c9f8(self);
}
