/* LBPMATCH module=EBOOT.BIN start=0x08a6d93c end=0x08a6dab8 symbol=FUN_08a6d93c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Stream {
    char pad0[4];
    char *cur;
    char pad1[0x0c];
    int count;
    char pad2[0x18];
    int owner;
} Stream;
typedef struct Wrap { Stream *s; } Wrap;
typedef struct Obj {
    char pad0[0x24c];
    int i0;
    float f1;
    int pad254;
    float f3;
    char blob[80];
} Obj;
extern unsigned char FUN_08954cc4(int p);
extern void FUN_08a34774(Obj *o, Wrap *w, unsigned int tag);
extern void FUN_08a56ec8(void *sub, Wrap *w, Obj *o);
extern void FUN_08954e6c(Stream *s, void *data, int size, int n);
extern void FUN_0895541c(Wrap *w);
static inline void put_float(Wrap *w, float val)
{
    Stream *s = w->s;
    float v = val;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
static inline void put_int(Wrap *w, int val)
{
    Stream *s = w->s;
    int v = val;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
void FUN_08a6d93c(Obj *o, Wrap *w)
{
    FUN_08a34774(o, w, 0x4353554d);
    FUN_08a56ec8((char *)o + 0xbc, w, o);
    put_int(w, o->i0);
    put_float(w, o->f1);
    put_int(w, 0);
    put_float(w, o->f3);
    FUN_08954e6c(w->s, o->blob, 1, 80);
    FUN_0895541c(w);
}
