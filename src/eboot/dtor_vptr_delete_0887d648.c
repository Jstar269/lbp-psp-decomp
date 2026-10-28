/* LBPMATCH module=EBOOT.BIN start=0x0887d648 end=0x0887d658 symbol=FUN_0887d648 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08873a2c, tail call). */
extern char DAT_08bb08f8[];
extern void FUN_08873a2c(void *self);
void FUN_0887d648(void **self)
{
    *self = DAT_08bb08f8;
    FUN_08873a2c(self);
}
