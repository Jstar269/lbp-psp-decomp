/* LBPMATCH module=EBOOT.BIN start=0x089c8764 end=0x089c8794 symbol=FUN_089c8764 lang=c99 */
/* Clone of src/eboot/ctor_set_vtbl_08988934.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { void *vtbl; } Obj;
extern void *DAT_08bc0fe8;
extern void FUN_08974824(Obj *, int, void *);
void FUN_089c8764(Obj *o, int a, void *b)
{
    FUN_08974824(o, a, b);
    o->vtbl = &DAT_08bc0fe8;
}
