/* LBPMATCH module=EBOOT.BIN start=0x08b880e0 end=0x08b88114 symbol=FUN_08b880e0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bd8a90[];
extern void FUN_08b891d0(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08b880e0(void **self)
{
    *self = DAT_08bd8a90;
    FUN_08b891d0(self);
    FUN_08a9e0cc(self);
}
