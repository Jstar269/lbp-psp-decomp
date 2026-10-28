/* LBPMATCH module=EBOOT.BIN start=0x08882398 end=0x088823cc symbol=FUN_08882398 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb0b40[];
extern void FUN_0886cd04(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08882398(void **self)
{
    *self = DAT_08bb0b40;
    FUN_0886cd04(self);
    FUN_08a9e0cc(self);
}
