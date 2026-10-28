/* LBPMATCH module=EBOOT.BIN start=0x08b8e204 end=0x08b8e214 symbol=FUN_08b8e204 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08b8e0f0, tail call). */
extern char DAT_08bd8f70[];
extern void FUN_08b8e0f0(void *self);
void FUN_08b8e204(void **self)
{
    *self = DAT_08bd8f70;
    FUN_08b8e0f0(self);
}
