/* LBPMATCH module=EBOOT.BIN start=0x08943578 end=0x08943650 symbol=FUN_08943578 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Mutex { int a; };
extern Mutex DAT_08bef8f4;
struct Obj { void (**vt)(Obj *); char pad[124]; };
struct Pool {
    Obj *base; Obj **stack; unsigned cap; int top; int heap_count;
    bool owns(Obj *p) { return p >= base && p < base + cap; }
    void put(Obj *p) { top--; stack[top] = p; }
};
extern Pool DAT_08beda80;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adb8a4(void *p);
inline void destroy(Obj *p) { p->vt[0](p); }
inline void free_heap(Pool *pool, Obj *p)
{
    if (p) {
        pool->heap_count--;
        destroy(p);
        FUN_08adb8a4(p);
    }
}
extern "C" void FUN_08943578(char *x)
{
    Obj *p = (Obj *)(x - 104);
    FUN_08ad3088(&DAT_08bef8f4);
    if (DAT_08beda80.owns(p)) {
        DAT_08beda80.put(p);
        destroy(p);
    } else {
        free_heap(&DAT_08beda80, p);
    }
    FUN_08ad2810(&DAT_08bef8f4);
}
