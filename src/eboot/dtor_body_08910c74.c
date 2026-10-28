/* LBPMATCH module=EBOOT.BIN start=0x08910c74 end=0x08910ca8 symbol=FUN_08910c74 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb6120[];
extern void FUN_0891077c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08910c74(void **self)
{
    *self = DAT_08bb6120;
    FUN_0891077c(self);
    FUN_08a9e0cc(self);
}
