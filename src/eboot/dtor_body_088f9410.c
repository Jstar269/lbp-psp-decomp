/* LBPMATCH module=EBOOT.BIN start=0x088f9410 end=0x088f9444 symbol=FUN_088f9410 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bb4f48[];
extern void FUN_0891077c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_088f9410(void **self)
{
    *self = DAT_08bb4f48;
    FUN_0891077c(self);
    FUN_08a9e0cc(self);
}
