/* LBPMATCH module=EBOOT.BIN start=0x0896f85c end=0x0896f8d0 symbol=FUN_0896f85c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp4d, Claude Sonnet 5.5); exact match verified; names and types await human review. Placement new with a throw() operator reproduces the null check on the element address. */
inline void *operator new(unsigned, void *p) throw() { return p; }
extern "C" void *DAT_08be84a0;
extern "C" void *FUN_08adbb84(void *, int);
extern "C" void FUN_08b88fac(void *, void *);
struct Elem { int v; Elem(int x) : v(x) {} };
struct Node { int a; int b; Elem item; };
struct Child { char pad[8]; int owner; };
struct Parent { char pad[0x44]; struct { int a; int b; } slots[1]; };
extern "C" void FUN_0896f85c(Parent *p, int i, Child *c)
{
    void *pos = &p->slots[i];
    Node *n = (Node *)FUN_08adbb84(DAT_08be84a0, 12);
    new (&n->item) Elem((int)c);
    FUN_08b88fac(n, pos);
    c->owner = (int)p;
}
