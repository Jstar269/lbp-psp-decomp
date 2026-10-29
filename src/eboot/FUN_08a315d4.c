/* LBPMATCH module=EBOOT.BIN start=0x08a315d4 end=0x08a3174c symbol=FUN_08a315d4 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Elem { char b[36]; } Elem;
typedef struct Reader { int pad0; char *base; char *cur; int pad0c; int off; } Reader;
typedef struct Obj { unsigned int count; Elem *items; int a; int b; int c; int d; } Obj;
extern void *FUN_08a9e824(unsigned int n);
extern void FUN_08a98ecc(Elem *e);
extern void *FUN_08b9e7a8(void *d, const void *s, unsigned int n);
static inline void get_int(Reader *r, void *dst)
{
    __builtin_memcpy(dst, r->cur, 4);
    r->off += 4;
    r->cur = r->base + r->off;
}
void FUN_08a315d4(Obj *o, Reader *r)
{
    get_int(r, &o->count);
    unsigned int n = o->count;
    Elem *items = (Elem *)FUN_08a9e824(n * 36);
    unsigned int i;
    for (i = 0; i != n; i++)
        FUN_08a98ecc(&items[i]);
    o->items = items;
    unsigned int bytes = o->count * 36;
    FUN_08b9e7a8(items, r->cur, bytes);
    int off = r->off + bytes;
    r->off = off;
    r->cur = r->base + off;
    get_int(r, &o->a);
    get_int(r, &o->b);
    get_int(r, &o->c);
    get_int(r, &o->d);
}
