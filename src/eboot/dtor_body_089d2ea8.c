/* LBPMATCH module=EBOOT.BIN start=0x089d2ea8 end=0x089d2edc symbol=FUN_089d2ea8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc1670[];
extern void FUN_0896cd08(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089d2ea8(void **self)
{
    *self = DAT_08bc1670;
    FUN_0896cd08(self);
    FUN_08a9e0cc(self);
}
