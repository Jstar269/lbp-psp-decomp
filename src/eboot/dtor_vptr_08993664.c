/* LBPMATCH module=EBOOT.BIN start=0x08993664 end=0x08993674 symbol=FUN_08993664 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_vptr_088044e8.c (lbpclone.py tag c9): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. A C++ destructor body of a class with a virtual destructor and nothing to destroy: it only resets the vtable pointer. */
extern char DAT_08babc90[];
void FUN_08993664(void **self)
{
    *self = DAT_08babc90;
}
