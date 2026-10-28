/* LBPMATCH module=EBOOT.BIN start=0x08b88124 end=0x08b88158 symbol=FUN_08b88124 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bd8a50[];
extern void FUN_08b891d0(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08b88124(void **self)
{
    *self = DAT_08bd8a50;
    FUN_08b891d0(self);
    FUN_08a9e0cc(self);
}
