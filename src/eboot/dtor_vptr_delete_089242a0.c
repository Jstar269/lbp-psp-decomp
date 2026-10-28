/* LBPMATCH module=EBOOT.BIN start=0x089242a0 end=0x089242b0 symbol=FUN_089242a0 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0894a260, tail call). */
extern char DAT_08bb6b28[];
extern void FUN_0894a260(void *self);
void FUN_089242a0(void **self)
{
    *self = DAT_08bb6b28;
    FUN_0894a260(self);
}
