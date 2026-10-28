/* LBPMATCH module=EBOOT.BIN start=0x08991e0c end=0x08991e40 symbol=FUN_08991e0c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bbfd48[];
extern void FUN_0897489c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08991e0c(void **self)
{
    *self = DAT_08bbfd48;
    FUN_0897489c(self);
    FUN_08a9e0cc(self);
}
