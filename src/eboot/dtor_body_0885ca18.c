/* LBPMATCH module=EBOOT.BIN start=0x0885ca18 end=0x0885ca4c symbol=FUN_0885ca18 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08baf6c8[];
extern void FUN_0887e664(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0885ca18(void **self)
{
    *self = DAT_08baf6c8;
    FUN_0887e664(self);
    FUN_08a9e0cc(self);
}
