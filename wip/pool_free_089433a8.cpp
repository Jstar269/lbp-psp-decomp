/* LBPMATCH module=EBOOT.BIN start=0x089433a8 end=0x08943488 symbol=FUN_089433a8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { virtual void destroy(); char body[108]; };
struct Pool { Obj *base; Obj **freelist; int cap; int nfree; int live; };
extern "C" Pool DAT_08bedec0;
extern "C" int DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adb8a4(void *);
extern "C" void FUN_089433a8(char *p)
{
    FUN_08ad3088(&DAT_08bef8f4);
    Obj *o = (Obj *)(p - 104);
    Pool *pool = &DAT_08bedec0;
    if (o >= pool->base && o < pool->base + pool->cap) {
        pool->freelist[--pool->nfree] = o;
        o->destroy();
    } else if (o != 0) {
        pool->live--;
        o->destroy();
        FUN_08adb8a4(o);
    }
    FUN_08ad2810(&DAT_08bef8f4);
}
// NEAR ~26 words (54/56): pool-slot release under the heap lock (obj = this-104; pool at DAT_08bedec0: base, freelist, cap, nfree, live; entries 112 bytes; destroy is virtual slot 0).
// remaining: retail lays the pool block first, then the out-of-line "o != 0" tail after the epilogue with both range tests branching into it, and stores the freelist entry before nfree (nfree store in the jalr delay slot); ours fuses the tests differently. The lock must be extern int DAT + &DAT (lui/addiu each time).
// tried: --nfree vs n = nfree-1 first, Ghidra if/else nesting, O2.
// near miss from lane lbp8c (unreviewed)
