/* LBPMATCH module=EBOOT.BIN start=0x08954a54 end=0x08954ab4 symbol=FUN_08954a54 lang=c99 */
/* Clone of src/eboot/call_two_virtuals_0894c398.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Iface { int (**vtbl)(struct Iface *); } Iface;
typedef struct Obj { char pad[0xa8]; Iface *src; int cached; } Obj;
int FUN_08954a54(Obj *o)
{
    int r = o->src->vtbl[2](o->src);
    o->cached = o->src->vtbl[9](o->src) + 12;
    return r;
}
