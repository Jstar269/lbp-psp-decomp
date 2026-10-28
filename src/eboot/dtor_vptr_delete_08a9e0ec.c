/* LBPMATCH module=EBOOT.BIN start=0x08a9e0ec end=0x08a9e0fc symbol=FUN_08a9e0ec lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a9df6c, tail call). */
extern char DAT_08bcac80[];
extern void FUN_08a9df6c(void *self);
void FUN_08a9e0ec(void **self)
{
    *self = DAT_08bcac80;
    FUN_08a9df6c(self);
}
