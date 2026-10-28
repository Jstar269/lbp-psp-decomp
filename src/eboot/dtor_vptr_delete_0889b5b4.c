/* LBPMATCH module=EBOOT.BIN start=0x0889b5b4 end=0x0889b5c4 symbol=FUN_0889b5b4 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0889a8c0, tail call). */
extern char DAT_08bb17c0[];
extern void FUN_0889a8c0(void *self);
void FUN_0889b5b4(void **self)
{
    *self = DAT_08bb17c0;
    FUN_0889a8c0(self);
}
