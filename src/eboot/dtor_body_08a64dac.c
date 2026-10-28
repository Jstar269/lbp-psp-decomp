/* LBPMATCH module=EBOOT.BIN start=0x08a64dac end=0x08a64de0 symbol=FUN_08a64dac lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc7250[];
extern void FUN_08a6ae78(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a64dac(void **self)
{
    *self = DAT_08bc7250;
    FUN_08a6ae78(self);
    FUN_08a9e0cc(self);
}
