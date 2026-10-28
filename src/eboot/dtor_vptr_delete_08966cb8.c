/* LBPMATCH module=EBOOT.BIN start=0x08966cb8 end=0x08966cc8 symbol=FUN_08966cb8 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_089e8e48, tail call). */
extern char DAT_08bb8878[];
extern void FUN_089e8e48(void *self);
void FUN_08966cb8(void **self)
{
    *self = DAT_08bb8878;
    FUN_089e8e48(self);
}
