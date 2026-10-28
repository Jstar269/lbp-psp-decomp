/* LBPMATCH module=EBOOT.BIN start=0x08a00d28 end=0x08a00d5c symbol=FUN_08a00d28 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc2e50[];
extern void FUN_089fa9e0(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a00d28(void **self)
{
    *self = DAT_08bc2e50;
    FUN_089fa9e0(self);
    FUN_08a9e0cc(self);
}
