/* LBPMATCH module=EBOOT.BIN start=0x089cc628 end=0x089cc638 symbol=FUN_089cc628 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_089d33d4, tail call). */
extern char DAT_08bc12d8[];
extern void FUN_089d33d4(void *self);
void FUN_089cc628(void **self)
{
    *self = DAT_08bc12d8;
    FUN_089d33d4(self);
}
