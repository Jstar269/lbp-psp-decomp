/* LBPMATCH module=EBOOT.BIN start=0x089ac4bc end=0x089ac4f0 symbol=FUN_089ac4bc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc07e8[];
extern void FUN_089dd09c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089ac4bc(void **self)
{
    *self = DAT_08bc07e8;
    FUN_089dd09c(self);
    FUN_08a9e0cc(self);
}
