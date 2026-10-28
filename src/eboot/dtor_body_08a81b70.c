/* LBPMATCH module=EBOOT.BIN start=0x08a81b70 end=0x08a81ba4 symbol=FUN_08a81b70 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc8a00[];
extern void FUN_08a9a0b8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a81b70(void **self)
{
    *self = DAT_08bc8a00;
    FUN_08a9a0b8(self);
    FUN_08a9e0cc(self);
}
