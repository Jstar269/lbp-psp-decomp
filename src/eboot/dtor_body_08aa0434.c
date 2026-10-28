/* LBPMATCH module=EBOOT.BIN start=0x08aa0434 end=0x08aa0468 symbol=FUN_08aa0434 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bcad50[];
extern void FUN_08a9fe88(void *self);
extern void FUN_08a9adc8(void *self);
void FUN_08aa0434(void **self)
{
    *self = DAT_08bcad50;
    FUN_08a9fe88(self);
    FUN_08a9adc8(self);
}
