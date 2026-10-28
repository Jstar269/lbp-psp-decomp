/* LBPMATCH module=EBOOT.BIN start=0x08a6ae98 end=0x08a6aecc symbol=FUN_08a6ae98 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc7890[];
extern void FUN_08a5f18c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a6ae98(void **self)
{
    *self = DAT_08bc7890;
    FUN_08a5f18c(self);
    FUN_08a9e0cc(self);
}
