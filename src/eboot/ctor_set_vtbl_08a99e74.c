/* LBPMATCH module=EBOOT.BIN start=0x08a99e74 end=0x08a99ea4 symbol=FUN_08a99e74 lang=c99 */
/* Clone of src/eboot/ctor_set_vtbl_08988934.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { void *vtbl; } Obj;
extern void *DAT_08bca908;
extern void FUN_08a356a4(Obj *, int, void *);
void FUN_08a99e74(Obj *o, int a, void *b)
{
    FUN_08a356a4(o, a, b);
    o->vtbl = &DAT_08bca908;
}
