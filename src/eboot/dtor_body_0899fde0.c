/* LBPMATCH module=EBOOT.BIN start=0x0899fde0 end=0x0899fe14 symbol=FUN_0899fde0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0588[];
extern void FUN_089e0a0c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_0899fde0(void **self)
{
    *self = DAT_08bc0588;
    FUN_089e0a0c(self);
    FUN_08a9e0cc(self);
}
