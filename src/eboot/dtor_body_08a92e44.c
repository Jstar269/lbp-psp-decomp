/* LBPMATCH module=EBOOT.BIN start=0x08a92e44 end=0x08a92e78 symbol=FUN_08a92e44 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bca0a0[];
extern void FUN_08a0a8ec(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a92e44(void **self)
{
    *self = DAT_08bca0a0;
    FUN_08a0a8ec(self);
    FUN_08a9e0cc(self);
}
