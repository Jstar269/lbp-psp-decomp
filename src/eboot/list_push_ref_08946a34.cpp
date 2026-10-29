/* LBPMATCH module=EBOOT.BIN start=0x08946a34 end=0x08946ae4 symbol=FUN_08946a34 lang=c++ */
/* Clone of src/eboot/list_push_ref_08869a34.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned, void *p) throw() { return p; }
extern "C" void FUN_08ad3088(void *m);
extern "C" void FUN_08ad2810(void *m);
extern "C" void *FUN_08adbb84(void *heap, int size);
extern "C" void FUN_08b88fac(void *node, void *pos);
extern "C" int DAT_08bef8f4;
extern "C" char *DAT_08be84ac;
struct Obj { int f0; int rc; };
struct Ref {
    Obj *p;
    Ref(const Ref &o) {
        Obj *q = o.p;
        p = q;
        if (q) { FUN_08ad3088(&DAT_08bef8f4); ++q->rc; FUN_08ad2810(&DAT_08bef8f4); }
    }
};
struct Node { void *next; void *prev; Ref item; };
extern "C" void FUN_08946a34(void *pos, Ref *src)
{
    char *heap = DAT_08be84ac;
    FUN_08ad3088(heap + 32);
    Node *n = (Node *)FUN_08adbb84(heap, 12);
    FUN_08ad2810(heap + 32);
    new (&n->item) Ref(*src);
    FUN_08b88fac(n, pos);
}
