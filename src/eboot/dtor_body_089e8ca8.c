/* LBPMATCH module=EBOOT.BIN start=0x089e8ca8 end=0x089e8cdc symbol=FUN_089e8ca8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc1ff0[];
extern void FUN_089e8e48(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089e8ca8(void **self)
{
    *self = DAT_08bc1ff0;
    FUN_089e8e48(self);
    FUN_08a9e0cc(self);
}
