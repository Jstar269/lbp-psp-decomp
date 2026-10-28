/* LBPMATCH module=EBOOT.BIN start=0x089183f8 end=0x0891842c symbol=FUN_089183f8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb67b0[];
extern void FUN_08916130(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089183f8(void **self)
{
    *self = DAT_08bb67b0;
    FUN_08916130(self);
    FUN_08a9e0cc(self);
}
