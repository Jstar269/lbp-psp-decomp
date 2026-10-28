/* LBPMATCH module=EBOOT.BIN start=0x08a10da4 end=0x08a10dd8 symbol=FUN_08a10da4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc3148[];
extern void FUN_08a0a8ec(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a10da4(void **self)
{
    *self = DAT_08bc3148;
    FUN_08a0a8ec(self);
    FUN_08a9e0cc(self);
}
