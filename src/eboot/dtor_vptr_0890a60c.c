/* LBPMATCH module=EBOOT.BIN start=0x0890a60c end=0x0890a61c symbol=FUN_0890a60c lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_088044e8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. A C++ destructor body of a class with a virtual destructor and nothing to destroy: it only resets the vtable pointer. */
extern char DAT_08bb5f50[];
void FUN_0890a60c(void **self)
{
    *self = DAT_08bb5f50;
}
