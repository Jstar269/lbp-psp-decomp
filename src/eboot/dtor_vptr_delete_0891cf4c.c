/* LBPMATCH module=EBOOT.BIN start=0x0891cf4c end=0x0891cf5c symbol=FUN_0891cf4c lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0894a260, tail call). */
extern char DAT_08bb69a0[];
extern void FUN_0894a260(void *self);
void FUN_0891cf4c(void **self)
{
    *self = DAT_08bb69a0;
    FUN_0894a260(self);
}
