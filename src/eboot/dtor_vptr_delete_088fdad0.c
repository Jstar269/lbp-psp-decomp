/* LBPMATCH module=EBOOT.BIN start=0x088fdad0 end=0x088fdae0 symbol=FUN_088fdad0 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0891077c, tail call). */
extern char DAT_08bb4f48[];
extern void FUN_0891077c(void *self);
void FUN_088fdad0(void **self)
{
    *self = DAT_08bb4f48;
    FUN_0891077c(self);
}
