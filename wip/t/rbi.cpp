/* LBPMATCH module=EBOOT.BIN start=0x08805418 end=0x088054dc symbol=FUN_08805418 lang=c++ cc=gcc404x-Os */
/* NOTE */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { unsigned key; unsigned val; };
struct Node { int color; Node *parent; Node *left; Node *right; Value v; };
struct Tree { int compare; Node header; unsigned count; };
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b899e4(bool insert_left, Node *z, Node *p, Node *header);
extern void *DAT_08be84a0;
extern "C" Node *FUN_08805418(Tree *t, Node *x, Node *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || v.key < p->v.key);
    Node *z = (Node *)FUN_08adbb84(DAT_08be84a0, sizeof(Node));
    new (&z->v) Value(v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
