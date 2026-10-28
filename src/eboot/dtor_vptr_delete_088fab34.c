/* LBPMATCH module=EBOOT.BIN start=0x088fab34 end=0x088fab44 symbol=FUN_088fab34 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08910604, tail call). */
extern char DAT_08bb5950[];
extern void FUN_08910604(void *self);
void FUN_088fab34(void **self)
{
    *self = DAT_08bb5950;
    FUN_08910604(self);
}
