/* LBPMATCH module=EBOOT.BIN start=0x0885c9f8 end=0x0885ca08 symbol=FUN_0885c9f8 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0887e664, tail call). */
extern char DAT_08baf6c8[];
extern void FUN_0887e664(void *self);
void FUN_0885c9f8(void **self)
{
    *self = DAT_08baf6c8;
    FUN_0887e664(self);
}
