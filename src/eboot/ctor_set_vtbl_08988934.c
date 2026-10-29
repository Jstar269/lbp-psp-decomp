/* LBPMATCH module=EBOOT.BIN start=0x08988934 end=0x08988964 symbol=FUN_08988934 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { void *vtbl; } Obj;
extern void *DAT_08bbf598;
extern void FUN_08974824(Obj *, int, void *);
void FUN_08988934(Obj *o, int a, void *b)
{
    FUN_08974824(o, a, b);
    o->vtbl = &DAT_08bbf598;
}
