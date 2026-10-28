/* LBPMATCH module=EBOOT.BIN start=0x088b1144 end=0x088b1154 symbol=FUN_088b1144 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_088b2df4, tail call). */
extern char DAT_08bb30a8[];
extern void FUN_088b2df4(void *self);
void FUN_088b1144(void **self)
{
    *self = DAT_08bb30a8;
    FUN_088b2df4(self);
}
