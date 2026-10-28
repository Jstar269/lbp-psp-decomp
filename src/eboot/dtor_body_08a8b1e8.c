/* LBPMATCH module=EBOOT.BIN start=0x08a8b1e8 end=0x08a8b21c symbol=FUN_08a8b1e8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc9490[];
extern void FUN_08a89c80(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_08a8b1e8(void **self)
{
    *self = DAT_08bc9490;
    FUN_08a89c80(self);
    FUN_08a9e0cc(self);
}
