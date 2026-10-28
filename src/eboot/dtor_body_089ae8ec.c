/* LBPMATCH module=EBOOT.BIN start=0x089ae8ec end=0x089ae920 symbol=FUN_089ae8ec lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0968[];
extern void FUN_0896b250(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089ae8ec(void **self)
{
    *self = DAT_08bc0968;
    FUN_0896b250(self);
    FUN_08a9e0cc(self);
}
