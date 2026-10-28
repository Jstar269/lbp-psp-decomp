/* LBPMATCH module=EBOOT.BIN start=0x08b881ac end=0x08b881e0 symbol=FUN_08b881ac lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bd89e0[];
extern void FUN_08b895d8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08b881ac(void **self)
{
    *self = DAT_08bd89e0;
    FUN_08b895d8(self);
    FUN_08a9e0cc(self);
}
