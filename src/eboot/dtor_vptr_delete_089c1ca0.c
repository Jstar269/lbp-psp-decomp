/* LBPMATCH module=EBOOT.BIN start=0x089c1ca0 end=0x089c1cb0 symbol=FUN_089c1ca0 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_089dd09c, tail call). */
extern char DAT_08bc0fa8[];
extern void FUN_089dd09c(void *self);
void FUN_089c1ca0(void **self)
{
    *self = DAT_08bc0fa8;
    FUN_089dd09c(self);
}
