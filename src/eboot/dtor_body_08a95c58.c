/* LBPMATCH module=EBOOT.BIN start=0x08a95c58 end=0x08a95c8c symbol=FUN_08a95c58 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bca4d8[];
extern void FUN_08a0a8ec(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a95c58(void **self)
{
    *self = DAT_08bca4d8;
    FUN_08a0a8ec(self);
    FUN_08a9e0cc(self);
}
