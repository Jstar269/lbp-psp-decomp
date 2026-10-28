/* LBPMATCH module=EBOOT.BIN start=0x089fbc58 end=0x089fbc8c symbol=FUN_089fbc58 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc2d80[];
extern void FUN_089fa9e0(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089fbc58(void **self)
{
    *self = DAT_08bc2d80;
    FUN_089fa9e0(self);
    FUN_08a9e0cc(self);
}
