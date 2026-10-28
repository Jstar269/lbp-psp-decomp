/* LBPMATCH module=EBOOT.BIN start=0x089c0424 end=0x089c0458 symbol=FUN_089c0424 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0ed0[];
extern void FUN_08974bfc(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089c0424(void **self)
{
    *self = DAT_08bc0ed0;
    FUN_08974bfc(self);
    FUN_08a9e0cc(self);
}
