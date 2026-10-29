/* LBPMATCH module=EBOOT.BIN start=0x089d33a4 end=0x089d33d4 symbol=FUN_089d33a4 lang=c99 */
/* Clone of src/eboot/ctor_set_vtbl_08988934.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { void *vtbl; } Obj;
extern void *DAT_08bc16b0;
extern void FUN_0896b21c(Obj *, int, void *);
void FUN_089d33a4(Obj *o, int a, void *b)
{
    FUN_0896b21c(o, a, b);
    o->vtbl = &DAT_08bc16b0;
}
