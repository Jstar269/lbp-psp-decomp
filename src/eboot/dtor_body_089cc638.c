/* LBPMATCH module=EBOOT.BIN start=0x089cc638 end=0x089cc66c symbol=FUN_089cc638 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/dtor_body_089baa90.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc12d8[];
extern void FUN_089d33d4(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089cc638(void **self)
{
    *self = DAT_08bc12d8;
    FUN_089d33d4(self);
    FUN_08a9e0cc(self);
}
