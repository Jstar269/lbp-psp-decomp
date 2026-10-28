/* LBPMATCH module=EBOOT.BIN start=0x08940a88 end=0x08940ac0 symbol=FUN_08940a88 lang=c99 cc=gcc404xs-Os */
/* Clone of src/eboot/dtor_mutex_08839900.c (lbpclone.py tag c11): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. A C++ destructor body: resets the vtable pointer, destroys the mutex member at +20, then runs the base-class destructor (tail call). */
extern char DAT_08badf48[];
extern void FUN_08ad271c(void *mutex);
extern void FUN_08a9e0cc(void *self);
void FUN_08940a88(void **self)
{
    *self = DAT_08badf48;
    FUN_08ad271c(self + 5);
    FUN_08a9e0cc(self);
}
