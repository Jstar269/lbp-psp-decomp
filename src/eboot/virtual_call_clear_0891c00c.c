/* LBPMATCH module=EBOOT.BIN start=0x0891c00c end=0x0891c040 symbol=FUN_0891c00c lang=c99 cc=gcc410-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj;
typedef struct VT { void *slot[5]; void (*f14)(struct Obj *self); } VT;
typedef struct Obj { VT *vt; } Obj;
typedef struct H { char pad[0xa8]; Obj *o; } H;
void FUN_0891c00c(H *h, int *out)
{
    h->o->vt->f14(h->o);
    *out = 0;
}
