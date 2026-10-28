/* LBPMATCH module=EBOOT.BIN start=0x08954978 end=0x08954988 symbol=FUN_08954978 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08950404, tail call). */
extern char DAT_08bb7cb0[];
extern void FUN_08950404(void *self);
void FUN_08954978(void **self)
{
    *self = DAT_08bb7cb0;
    FUN_08950404(self);
}
