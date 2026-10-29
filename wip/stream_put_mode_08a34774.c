/* LBPMATCH module=EBOOT.BIN start=0x08a34774 end=0x08a348ac symbol=FUN_08a34774 lang=c99 cc=gcc404xs-O2 */
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
typedef struct Obj {
    char pad0[4];
    int f4;
    char pad1[0x28];
    float f30;
    char pad2[0x61];
    unsigned char b149;
    unsigned char b150;
} Obj;
extern unsigned char FUN_08954cc4(int p);
extern void FUN_08954ca4(Stream *s, int v);
extern void FUN_08954e28(Stream *s, int v);
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
void FUN_08a34774(Obj *o, Wrap *w, int a)
{
    int mode;
    FUN_08954ca4(w->s, a);
    FUN_08954e28(w->s, 4);
    put_int(w, o->f4);
    put_float(w, o->f30);
    mode = (o->b150 == 1);
    if (o->b149 == 1) mode = 2;
    put_int(w, mode);
}
// NEAR 13 words (78/78 words, same instruction multiset): scheduling only. Retail loads the third put's stream pointer (lw s0,0(s2)) and the two flag bytes
// interleaved with the previous put's cur/count update; ours does the previous update first, then the loads. mode = (b150 == 1); if (b149 == 1) mode = 2;
// gives retail's movz (a ?: chain gives branches). Tried: mode computed inside a hand-inlined put (branches, worse).
// near miss from lane lbp11a (unreviewed)
