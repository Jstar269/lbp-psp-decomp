/* LBPMATCH module=EBOOT.BIN start=0x089230b4 end=0x089230c4 symbol=FUN_089230b4 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0894a260, tail call). */
extern char DAT_08bb6af0[];
extern void FUN_0894a260(void *self);
void FUN_089230b4(void **self)
{
    *self = DAT_08bb6af0;
    FUN_0894a260(self);
}
