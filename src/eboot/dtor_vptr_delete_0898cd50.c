/* LBPMATCH module=EBOOT.BIN start=0x0898cd50 end=0x0898cd60 symbol=FUN_0898cd50 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0897905c, tail call). */
extern char DAT_08bbfb08[];
extern void FUN_0897905c(void *self);
void FUN_0898cd50(void **self)
{
    *self = DAT_08bbfb08;
    FUN_0897905c(self);
}
