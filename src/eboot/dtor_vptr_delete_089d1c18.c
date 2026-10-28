/* LBPMATCH module=EBOOT.BIN start=0x089d1c18 end=0x089d1c28 symbol=FUN_089d1c18 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_089d33d4, tail call). */
extern char DAT_08bc15b0[];
extern void FUN_089d33d4(void *self);
void FUN_089d1c18(void **self)
{
    *self = DAT_08bc15b0;
    FUN_089d33d4(self);
}
