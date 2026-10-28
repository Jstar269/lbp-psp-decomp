/* LBPMATCH module=EBOOT.BIN start=0x089d9aac end=0x089d9ae0 symbol=FUN_089d9aac lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc18e0[];
extern void FUN_089df2b8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089d9aac(void **self)
{
    *self = DAT_08bc18e0;
    FUN_089df2b8(self);
    FUN_08a9e0cc(self);
}
