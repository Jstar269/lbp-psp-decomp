/* LBPMATCH module=EBOOT.BIN start=0x088554ec end=0x08855520 symbol=FUN_088554ec lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08baf1b8[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_088554ec(void **self)
{
    *self = DAT_08baf1b8;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
