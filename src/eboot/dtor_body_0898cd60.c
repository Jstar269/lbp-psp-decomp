/* LBPMATCH module=EBOOT.BIN start=0x0898cd60 end=0x0898cd94 symbol=FUN_0898cd60 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bbfb08[];
extern void FUN_0897905c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0898cd60(void **self)
{
    *self = DAT_08bbfb08;
    FUN_0897905c(self);
    FUN_08a9e0cc(self);
}
