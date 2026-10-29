/* LBPMATCH module=EBOOT.BIN start=0x08840e70 end=0x08840f44 symbol=FUN_08840e70 lang=c++ */
/* Clone of src/eboot/pool_new_0883c534.cpp (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned, void *p) throw() { return p; }
struct Mutex { int a; };
extern Mutex DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void *FUN_08adb810(unsigned size, unsigned align, int a, int b);
extern "C" void FUN_08945ddc(void *o);
inline void *operator new(unsigned size, unsigned align, int a, int b) { return FUN_08adb810(size, align, a, b); }
struct Obj {
    char pad[128];
    Obj() { FUN_08945ddc(this); }
};
struct Pool { Obj *base; Obj **stack; int cap; int top; int heap_count; };
extern Pool DAT_08bedb38;
struct Handle {
    Obj *p;
    Handle() {}
    Handle(const Handle &);
};
inline Obj *make()
{
    Obj *o;
    if (DAT_08bedb38.top < DAT_08bedb38.cap) {
        o = new (DAT_08bedb38.stack[DAT_08bedb38.top++]) Obj;
    } else {
        DAT_08bedb38.heap_count++;
        o = new (16, 0, 0) Obj;
    }
    return o;
}
extern "C" Handle FUN_08840e70()
{
    Handle h;
    FUN_08ad3088(&DAT_08bef8f4);
    FUN_08ad3088(&DAT_08bef8f4);
    Obj *o = make();
    FUN_08ad2810(&DAT_08bef8f4);
    h.p = o;
    FUN_08ad2810(&DAT_08bef8f4);
    return h;
}
