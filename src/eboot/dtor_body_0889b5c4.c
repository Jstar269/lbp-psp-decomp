/* LBPMATCH module=EBOOT.BIN start=0x0889b5c4 end=0x0889b5f8 symbol=FUN_0889b5c4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb17c0[];
extern void FUN_0889a8c0(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0889b5c4(void **self)
{
    *self = DAT_08bb17c0;
    FUN_0889a8c0(self);
    FUN_08a9e0cc(self);
}
