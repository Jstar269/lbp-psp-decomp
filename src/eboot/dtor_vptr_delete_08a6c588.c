/* LBPMATCH module=EBOOT.BIN start=0x08a6c588 end=0x08a6c598 symbol=FUN_08a6c588 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_delete_088044f8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a35074, tail call). */
extern char DAT_08bc7b00[];
extern void FUN_08a35074(void *self);
void FUN_08a6c588(void **self)
{
    *self = DAT_08bc7b00;
    FUN_08a35074(self);
}
