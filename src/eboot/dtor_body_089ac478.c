/* LBPMATCH module=EBOOT.BIN start=0x089ac478 end=0x089ac4ac symbol=FUN_089ac478 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0538[];
extern void FUN_0896cd08(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089ac478(void **self)
{
    *self = DAT_08bc0538;
    FUN_0896cd08(self);
    FUN_08a9e0cc(self);
}
