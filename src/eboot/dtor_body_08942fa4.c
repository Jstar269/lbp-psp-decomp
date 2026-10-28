/* LBPMATCH module=EBOOT.BIN start=0x08942fa4 end=0x08942fd8 symbol=FUN_08942fa4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb7520[];
extern void FUN_0894a260(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08942fa4(void **self)
{
    *self = DAT_08bb7520;
    FUN_0894a260(self);
    FUN_08a9e0cc(self);
}
