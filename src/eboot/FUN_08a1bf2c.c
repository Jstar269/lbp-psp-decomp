/* LBPMATCH module=EBOOT.BIN start=0x08a1bf2c end=0x08a1c078 symbol=FUN_08a1bf2c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Reader { int pad0; char *base; char *cur; int pad0c; int off; } Reader;
typedef struct Obj { int f0, f1, f2, f3, f4, f5, f6, f7, f8; } Obj;
static inline void get_int(Reader *r, void *dst)
{
    __builtin_memcpy(dst, r->cur, 4);
    r->off += 4;
    r->cur = r->base + r->off;
}
void FUN_08a1bf2c(Obj *o, Reader *r)
{
    get_int(r, &o->f0);
    get_int(r, &o->f1);
    get_int(r, &o->f2);
    get_int(r, &o->f3);
    get_int(r, &o->f4);
    get_int(r, &o->f5);
    get_int(r, &o->f6);
    get_int(r, &o->f7);
    get_int(r, &o->f8);
}
