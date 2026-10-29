/* LBPMATCH module=EBOOT.BIN start=0x08a30cc0 end=0x08a30d7c symbol=FUN_08a30cc0 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Rc { void (**vtbl)(struct Rc *); int count; } Rc;
typedef struct Obj { void *vtbl; int f4; int f8; Rc *b; Rc *a; } Obj;
extern void *DAT_08bc3d48;
extern void *DAT_08bc3d30;
extern void FUN_08a9e0cc(Obj *);
static inline void release(Rc *p)
{
    if (p && --p->count == 0)
        p->vtbl[2](p);
}
void FUN_08a30cc0(Obj *o)
{
    o->vtbl = &DAT_08bc3d48;
    release(o->a);
    release(o->b);
    o->vtbl = &DAT_08bc3d30;
    FUN_08a9e0cc(o);
}
// NEAR 16 words: block layout. Ours puts the second release slow path (call + epilogue copy) before the first release slow path; retail has first then second.
// Tried: inline helper, merged && form, early-return duplicate, int n form, O2/402x/410; Os inlines the calls (35 off).
// near miss from lane lbp8b (unreviewed)
