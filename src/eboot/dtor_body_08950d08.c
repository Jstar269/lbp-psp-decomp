/* LBPMATCH module=EBOOT.BIN start=0x08950d08 end=0x08950d3c symbol=FUN_08950d08 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb7b68[];
extern void FUN_08950404(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08950d08(void **self)
{
    *self = DAT_08bb7b68;
    FUN_08950404(self);
    FUN_08a9e0cc(self);
}
