/* LBPMATCH module=EBOOT.BIN start=0x0891c0f0 end=0x0891c124 symbol=FUN_0891c0f0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/virtual_call_clear_0891c00c.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj;
typedef struct VT { void *slot[5]; void (*f14)(struct Obj *self); } VT;
typedef struct Obj { VT *vt; } Obj;
typedef struct H { char pad[0xa8]; Obj *o; } H;
void FUN_0891c0f0(H *h, int *out)
{
    h->o->vt->f14(h->o);
    *out = 0;
}
