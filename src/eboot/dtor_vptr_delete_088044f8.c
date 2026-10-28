/* LBPMATCH module=EBOOT.BIN start=0x088044f8 end=0x08804508 symbol=FUN_088044f8 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The deleting destructor of the same kind of class: reset the vtable pointer, then free the object (FUN_08a9e0cc, tail call). */
extern char DAT_08bab530[];
extern void FUN_08a9e0cc(void *self);
void FUN_088044f8(void **self)
{
    *self = DAT_08bab530;
    FUN_08a9e0cc(self);
}
