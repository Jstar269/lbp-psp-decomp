/* LBPMATCH module=EBOOT.BIN start=0x089ae5c4 end=0x089ae5d4 symbol=FUN_089ae5c4 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_089e0a0c, tail call). */
extern char DAT_08bc0908[];
extern void FUN_089e0a0c(void *self);
void FUN_089ae5c4(void **self)
{
    *self = DAT_08bc0908;
    FUN_089e0a0c(self);
}
