/* LBPMATCH module=EBOOT.BIN start=0x08992980 end=0x089929b4 symbol=FUN_08992980 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bbfe80[];
extern void FUN_0897489c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08992980(void **self)
{
    *self = DAT_08bbfe80;
    FUN_0897489c(self);
    FUN_08a9e0cc(self);
}
