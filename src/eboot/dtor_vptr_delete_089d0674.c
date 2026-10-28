/* LBPMATCH module=EBOOT.BIN start=0x089d0674 end=0x089d0684 symbol=FUN_089d0674 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0896cd08, tail call). */
extern char DAT_08bc14f0[];
extern void FUN_0896cd08(void *self);
void FUN_089d0674(void **self)
{
    *self = DAT_08bc14f0;
    FUN_0896cd08(self);
}
