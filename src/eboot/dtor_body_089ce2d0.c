/* LBPMATCH module=EBOOT.BIN start=0x089ce2d0 end=0x089ce304 symbol=FUN_089ce2d0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc13a8[];
extern void FUN_089ce210(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089ce2d0(void **self)
{
    *self = DAT_08bc13a8;
    FUN_089ce210(self);
    FUN_08a9e0cc(self);
}
