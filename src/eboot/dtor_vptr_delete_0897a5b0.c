/* LBPMATCH module=EBOOT.BIN start=0x0897a5b0 end=0x0897a5c0 symbol=FUN_0897a5b0 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0897a4a4, tail call). */
extern char DAT_08bbd940[];
extern void FUN_0897a4a4(void *self);
void FUN_0897a5b0(void **self)
{
    *self = DAT_08bbd940;
    FUN_0897a4a4(self);
}
