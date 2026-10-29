/* LBPMATCH module=EBOOT.BIN start=0x088b3728 end=0x088b37b8 symbol=FUN_088b3728 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" int DAT_08bef8f4;
extern "C" void *DAT_08be84a0;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b88fac(void *node, void *pos);
struct Rc { int pad; int count; };
struct Handle {
    Rc *r;
    Handle(const Handle &o) {
        Rc *rr = o.r;
        r = rr;
        if (rr) { FUN_08ad3088(&DAT_08bef8f4); rr->count++; FUN_08ad2810(&DAT_08bef8f4); }
    }
};
struct Node { void *next; void *prev; Handle h; };
extern "C" void FUN_088b3728(void *pos, const Handle *src)
{
    Node *z = (Node *)FUN_08adbb84(DAT_08be84a0, sizeof(Node));
    new (&z->h) Handle(*src);
    FUN_08b88fac(z, pos);
}
