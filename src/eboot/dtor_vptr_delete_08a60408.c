/* LBPMATCH module=EBOOT.BIN start=0x08a60408 end=0x08a60418 symbol=FUN_08a60408 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a99b80, tail call). */
extern char DAT_08bc6c30[];
extern void FUN_08a99b80(void *self);
void FUN_08a60408(void **self)
{
    *self = DAT_08bc6c30;
    FUN_08a99b80(self);
}
