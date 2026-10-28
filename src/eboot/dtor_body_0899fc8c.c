/* LBPMATCH module=EBOOT.BIN start=0x0899fc8c end=0x0899fcc0 symbol=FUN_0899fc8c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0538[];
extern void FUN_0896cd08(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0899fc8c(void **self)
{
    *self = DAT_08bc0538;
    FUN_0896cd08(self);
    FUN_08a9e0cc(self);
}
