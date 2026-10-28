/* LBPMATCH module=EBOOT.BIN start=0x0889b618 end=0x0889b628 symbol=FUN_0889b618 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0889a8c0, tail call). */
extern char DAT_08bb1810[];
extern void FUN_0889a8c0(void *self);
void FUN_0889b618(void **self)
{
    *self = DAT_08bb1810;
    FUN_0889a8c0(self);
}
