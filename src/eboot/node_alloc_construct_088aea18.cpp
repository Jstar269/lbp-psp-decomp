/* LBPMATCH module=EBOOT.BIN start=0x088aea18 end=0x088aea80 symbol=FUN_088aea18 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. Placement new with throw() gives the null check on the member address (matching idiom). */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value;
extern "C" void FUN_088ae998(Value *dst, const Value *src);
struct Value {
    unsigned a; unsigned b;
    Value(const Value &o) { FUN_088ae998(this, &o); }
};
struct Node { unsigned x; unsigned y; Value v; };
extern "C" Node *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b88fac(void *node, int tree);
extern "C" void *DAT_08be84a0;

extern "C" void FUN_088aea18(int param_1, const Value *param_2)
{
    Node *n = FUN_08adbb84(DAT_08be84a0, 0x10);
    new (&n->v) Value(*param_2);
    FUN_08b88fac(n, param_1);
}
