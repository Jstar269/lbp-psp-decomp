/* LBPMATCH module=EBOOT.BIN start=0x08a48ccc end=0x08a48d00 symbol=FUN_08a48ccc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc5490[];
extern void FUN_08a4a0f8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a48ccc(void **self)
{
    *self = DAT_08bc5490;
    FUN_08a4a0f8(self);
    FUN_08a9e0cc(self);
}
