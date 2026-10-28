/* LBPMATCH module=EBOOT.BIN start=0x08a8b1d8 end=0x08a8b1e8 symbol=FUN_08a8b1d8 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a89c80, tail call). */
extern char DAT_08bc9490[];
extern void FUN_08a89c80(void *self);
void FUN_08a8b1d8(void **self)
{
    *self = DAT_08bc9490;
    FUN_08a89c80(self);
}
