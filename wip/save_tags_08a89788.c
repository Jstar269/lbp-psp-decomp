/* LBPMATCH module=EBOOT.BIN start=0x08a89788 end=0x08a8985c symbol=FUN_08a89788 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
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
    char pad0[0x98];
    int a;
    char pad1[0xbc];
    int b;
} Obj;
extern unsigned char FUN_08954cc4(int p);
extern void FUN_08a34774(Obj *o, Wrap *w, unsigned int tag);
extern void FUN_0895541c(Wrap *w);
void FUN_08a89788(Obj *o, Wrap *w)
{
    int v1, v2;
    Stream *s1, *s2;
    FUN_08a34774(o, w, 0x54475453);
    s1 = w->s;
    v1 = o->a;
    if (!FUN_08954cc4(s1->owner)) {
        __builtin_memcpy(s1->cur, &v1, 4);
    }
    s1->cur += 4;
    s1->count += 4;
    v2 = o->b;
    s2 = w->s;
    if (!FUN_08954cc4(s2->owner)) {
        __builtin_memcpy(s2->cur, &v2, 4);
    }
    s2->cur += 4;
    s2->count += 4;
    FUN_0895541c(w);
}
// NEAR 2 words: in the second put block retail loads the value (lw v0,344(s3)) before lw a0,48(s1); ours has them swapped.
// Tried: value read before/after the Stream load, w->s->owner in the call, both values read up front (worse), inline helper with value/pointer args.
// Slots: two separate address-taken int locals (sp+0, sp+4) are needed; the helper's scope sharing one slot gives 4 words.
// near miss from lane lbp10c (unreviewed)
