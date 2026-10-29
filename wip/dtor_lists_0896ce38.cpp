/* LBPMATCH module=EBOOT.BIN start=0x0896ce38 end=0x0896ced8 symbol=FUN_0896ce38 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bb8940[];
extern void *DAT_08be84a0;
extern "C" void FUN_0896c85c(void *);
extern "C" void FUN_0896b250(void *);
extern "C" void FUN_08a9e0cc(void *);
extern "C" void FUN_08adbc24(void *, void *, unsigned);
struct Node { Node *next; Node *prev; };
struct L {
    Node head;
    int pad[4];
    ~L() {
        FUN_0896c85c(this);
        Node *n = head.next;
        while (n != &head) {
            Node *nn = n->next;
            FUN_08adbc24(DAT_08be84a0, n, 12);
            n = nn;
        }
    }
};
struct Base {
    const void *vt;
    int pad[5];
    ~Base() { FUN_0896b250(this); }
};
struct Obj : Base {
    L lists[2];
    ~Obj() { vt = DAT_08bb8940; }
};
extern "C" void FUN_0896ce38(Obj *p)
{
    p->~Obj();
    FUN_08a9e0cc(p);
}
// NEAR ~39 words: class with inline member-array destructor; GCC builds two induction variables (s2,s3) for the array-dtor loop where retail has one (s1), and the final tail call to 0x08a9e0cc is not formed.
// Tried: Obj class with L lists[2], hand loop with q-- and counter 3, Base class dtor.
// near miss from lane lbp9c (unreviewed)
