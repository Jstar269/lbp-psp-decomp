/* LBPMATCH module=EBOOT.BIN start=0x08b8e164 end=0x08b8e174 symbol=FUN_08b8e164 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08b8cdc4, tail call). */
extern char DAT_08bd8f28[];
extern void FUN_08b8cdc4(void *self);
void FUN_08b8e164(void **self)
{
    *self = DAT_08bd8f28;
    FUN_08b8cdc4(self);
}
