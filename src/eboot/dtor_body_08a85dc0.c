/* LBPMATCH module=EBOOT.BIN start=0x08a85dc0 end=0x08a85df4 symbol=FUN_08a85dc0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc8ce8[];
extern void FUN_08a6ae78(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a85dc0(void **self)
{
    *self = DAT_08bc8ce8;
    FUN_08a6ae78(self);
    FUN_08a9e0cc(self);
}
