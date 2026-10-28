/* LBPMATCH module=EBOOT.BIN start=0x089ae5d4 end=0x089ae608 symbol=FUN_089ae5d4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0908[];
extern void FUN_089e0a0c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089ae5d4(void **self)
{
    *self = DAT_08bc0908;
    FUN_089e0a0c(self);
    FUN_08a9e0cc(self);
}
