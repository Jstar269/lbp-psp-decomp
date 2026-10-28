/* LBPMATCH module=EBOOT.BIN start=0x089cc000 end=0x089cc034 symbol=FUN_089cc000 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc1270[];
extern void FUN_08974bfc(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089cc000(void **self)
{
    *self = DAT_08bc1270;
    FUN_08974bfc(self);
    FUN_08a9e0cc(self);
}
