/* LBPMATCH module=EBOOT.BIN start=0x08a870fc end=0x08a8710c symbol=FUN_08a870fc lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a3aa0c, tail call). */
extern char DAT_08bc8fa8[];
extern void FUN_08a3aa0c(void *self);
void FUN_08a870fc(void **self)
{
    *self = DAT_08bc8fa8;
    FUN_08a3aa0c(self);
}
