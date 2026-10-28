/* LBPMATCH module=EBOOT.BIN start=0x08998db4 end=0x08998de8 symbol=FUN_08998db4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0130[];
extern void FUN_0897489c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08998db4(void **self)
{
    *self = DAT_08bc0130;
    FUN_0897489c(self);
    FUN_08a9e0cc(self);
}
