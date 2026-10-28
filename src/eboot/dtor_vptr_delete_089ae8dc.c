/* LBPMATCH module=EBOOT.BIN start=0x089ae8dc end=0x089ae8ec symbol=FUN_089ae8dc lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0896b250, tail call). */
extern char DAT_08bc0968[];
extern void FUN_0896b250(void *self);
void FUN_089ae8dc(void **self)
{
    *self = DAT_08bc0968;
    FUN_0896b250(self);
}
