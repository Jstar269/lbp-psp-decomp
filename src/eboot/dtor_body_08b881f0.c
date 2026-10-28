/* LBPMATCH module=EBOOT.BIN start=0x08b881f0 end=0x08b88224 symbol=FUN_08b881f0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bd89a8[];
extern void FUN_08b895d8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08b881f0(void **self)
{
    *self = DAT_08bd89a8;
    FUN_08b895d8(self);
    FUN_08a9e0cc(self);
}
