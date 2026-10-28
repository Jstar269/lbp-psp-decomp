/* LBPMATCH module=EBOOT.BIN start=0x089d9c28 end=0x089d9c5c symbol=FUN_089d9c28 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc1930[];
extern void FUN_0896a34c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089d9c28(void **self)
{
    *self = DAT_08bc1930;
    FUN_0896a34c(self);
    FUN_08a9e0cc(self);
}
