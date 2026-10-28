/* LBPMATCH module=EBOOT.BIN start=0x08b881e0 end=0x08b881f0 symbol=FUN_08b881e0 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08b895d8, tail call). */
extern char DAT_08bd89a8[];
extern void FUN_08b895d8(void *self);
void FUN_08b881e0(void **self)
{
    *self = DAT_08bd89a8;
    FUN_08b895d8(self);
}
