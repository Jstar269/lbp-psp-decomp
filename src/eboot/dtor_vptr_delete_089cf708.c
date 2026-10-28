/* LBPMATCH module=EBOOT.BIN start=0x089cf708 end=0x089cf718 symbol=FUN_089cf708 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_089ce210, tail call). */
extern char DAT_08bc1428[];
extern void FUN_089ce210(void *self);
void FUN_089cf708(void **self)
{
    *self = DAT_08bc1428;
    FUN_089ce210(self);
}
