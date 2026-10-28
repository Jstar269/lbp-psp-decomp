/* LBPMATCH module=EBOOT.BIN start=0x089baa80 end=0x089baa90 symbol=FUN_089baa80 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0897905c, tail call). */
extern char DAT_08bc0a18[];
extern void FUN_0897905c(void *self);
void FUN_089baa80(void **self)
{
    *self = DAT_08bc0a18;
    FUN_0897905c(self);
}
