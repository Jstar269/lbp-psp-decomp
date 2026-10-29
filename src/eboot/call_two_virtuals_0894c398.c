/* LBPMATCH module=EBOOT.BIN start=0x0894c398 end=0x0894c3f8 symbol=FUN_0894c398 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Iface { int (**vtbl)(struct Iface *); } Iface;
typedef struct Obj { char pad[0xa8]; Iface *src; int cached; } Obj;
int FUN_0894c398(Obj *o)
{
    int r = o->src->vtbl[2](o->src);
    o->cached = o->src->vtbl[9](o->src) + 12;
    return r;
}
