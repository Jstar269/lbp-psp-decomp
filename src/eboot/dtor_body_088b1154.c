/* LBPMATCH module=EBOOT.BIN start=0x088b1154 end=0x088b1188 symbol=FUN_088b1154 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb30a8[];
extern void FUN_088b2df4(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_088b1154(void **self)
{
    *self = DAT_08bb30a8;
    FUN_088b2df4(self);
    FUN_08a9e0cc(self);
}
