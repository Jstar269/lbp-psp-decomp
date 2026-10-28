/* LBPMATCH module=EBOOT.BIN start=0x08a8710c end=0x08a87140 symbol=FUN_08a8710c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc8fa8[];
extern void FUN_08a3aa0c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a8710c(void **self)
{
    *self = DAT_08bc8fa8;
    FUN_08a3aa0c(self);
    FUN_08a9e0cc(self);
}
