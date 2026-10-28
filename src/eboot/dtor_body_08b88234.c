/* LBPMATCH module=EBOOT.BIN start=0x08b88234 end=0x08b88268 symbol=FUN_08b88234 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bd8970[];
extern void FUN_08b895d8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08b88234(void **self)
{
    *self = DAT_08bd8970;
    FUN_08b895d8(self);
    FUN_08a9e0cc(self);
}
