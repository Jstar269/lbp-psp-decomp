/* LBPMATCH module=EBOOT.BIN start=0x08b8e214 end=0x08b8e248 symbol=FUN_08b8e214 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bd8f70[];
extern void FUN_08b8e0f0(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08b8e214(void **self)
{
    *self = DAT_08bd8f70;
    FUN_08b8e0f0(self);
    FUN_08a9e0cc(self);
}
