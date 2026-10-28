/* LBPMATCH module=EBOOT.BIN start=0x089ac958 end=0x089ac968 symbol=FUN_089ac958 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_0896cd08, tail call). */
extern char DAT_08bc0538[];
extern void FUN_0896cd08(void *self);
void FUN_089ac958(void **self)
{
    *self = DAT_08bc0538;
    FUN_0896cd08(self);
}
