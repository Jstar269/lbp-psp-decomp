/* LBPMATCH module=EBOOT.BIN start=0x0889a8c0 end=0x0889a8d0 symbol=FUN_0889a8c0 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_088044e8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. A C++ destructor body of a class with a virtual destructor and nothing to destroy: it only resets the vtable pointer. */
extern char DAT_08bb16a0[];
void FUN_0889a8c0(void **self)
{
    *self = DAT_08bb16a0;
}
