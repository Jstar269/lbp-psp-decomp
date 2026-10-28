/* LBPMATCH module=EBOOT.BIN start=0x089e8e68 end=0x089e8e78 symbol=FUN_089e8e68 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a9e0cc, tail call). */
extern char DAT_08bc2010[];
extern void FUN_08a9e0cc(void *self);
void FUN_089e8e68(void **self)
{
    *self = DAT_08bc2010;
    FUN_08a9e0cc(self);
}
