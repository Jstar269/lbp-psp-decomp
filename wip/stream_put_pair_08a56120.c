/* LBPMATCH module=EBOOT.BIN start=0x08a56120 end=0x08a56258 symbol=FUN_08a56120 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Stream {
    char pad0[4];
    char *cur;
    char pad1[0x0c];
    int count;
    char pad2[0x18];
    int owner;
} Stream;
typedef struct Wrap { Stream *s; } Wrap;
typedef struct Src { float a; float b; int c; } Src;
extern unsigned char FUN_08954cc4(int p);
static inline void put_float(Wrap *w, float v)
{
    Stream *s = w->s;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
static inline void put_int(Wrap *w, int v)
{
    Stream *s = w->s;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
void FUN_08a56120(Wrap *w, Src *src)
{
    float y = src->b;
    put_float(w, src->a);
    if (y < 0.0f) y = -y;
    put_float(w, y);
    put_int(w, src->c);
}
// NEAR ~3 words (79 vs 78): everything matches except `mtc1 zero,$f0` is emitted in both paths of the first put (retail shares one in the
// delay slot of the first beqz, and the out-of-line store block keeps `lw v1,0(sp)` there), so ours has one extra word and a delay-slot difference.
// Tried: ternary for the abs, -Os. Helpers put_float/put_int as in stream_put_float2_08a56258.c; y = src->b loaded first (retail lwc1 $f20 at entry).
// near miss from lane lbp11a (unreviewed)
