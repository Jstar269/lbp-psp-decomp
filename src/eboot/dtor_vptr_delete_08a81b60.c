/* LBPMATCH module=EBOOT.BIN start=0x08a81b60 end=0x08a81b70 symbol=FUN_08a81b60 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a9a0b8, tail call). */
extern char DAT_08bc8a00[];
extern void FUN_08a9a0b8(void *self);
void FUN_08a81b60(void **self)
{
    *self = DAT_08bc8a00;
    FUN_08a9a0b8(self);
}
