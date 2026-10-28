/* LBPMATCH module=EBOOT.BIN start=0x08a433fc end=0x08a43430 symbol=FUN_08a433fc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc4f40[];
extern void FUN_08a4a0f8(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a433fc(void **self)
{
    *self = DAT_08bc4f40;
    FUN_08a4a0f8(self);
    FUN_08a9e0cc(self);
}
