/* LBPMATCH module=EBOOT.BIN start=0x089cad80 end=0x089cad90 symbol=FUN_089cad80 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0897489c, tail call). */
extern char DAT_08bc1228[];
extern void FUN_0897489c(void *self);
void FUN_089cad80(void **self)
{
    *self = DAT_08bc1228;
    FUN_0897489c(self);
}
