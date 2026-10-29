/* LBPMATCH module=EBOOT.BIN start=0x0895094c end=0x08950a84 symbol=FUN_0895094c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  virtual void v0();
  virtual void release();
  int refs;
};
struct Pool;
extern "C" void *DAT_08bb7b00[];
extern "C" void *DAT_08bb7ac8[];
extern "C" void *DAT_08bb7a48[];
extern "C" Pool *DAT_08be84a0;
struct Tree;
extern "C" void FUN_0895082c(Tree *t);
extern "C" void FUN_08950504(Tree *t, struct TNode *n);
extern "C" void FUN_08adbc24(Pool *pool, void *p, int size);
extern "C" void FUN_08a9df6c(int h);

struct LNode {
  LNode *next;
  LNode *prev;
};
struct TNode {
  char pad[8];
  TNode *next;
  TNode *child;
  int padx;
  Obj *obj;
};
struct Tree {
  char pad[8];
  TNode *root;
  ~Tree()
  {
    TNode *t = root;
    while (t) {
      FUN_08950504(this, t->child);
      Obj *o = t->obj;
      TNode *nx = t->next;
      if (o) {
        int r = o->refs - 1;
        o->refs = r;
        if (r == 0) o->release();
      }
      FUN_08adbc24(DAT_08be84a0, t, 24);
      t = nx;
    }
  }
};
struct List {
  LNode head;
  void free_nodes()
  {
    LNode *n = head.next;
    while (n != &head) {
      LNode *nx = n->next;
      FUN_08adbc24(DAT_08be84a0, n, 12);
      n = nx;
    }
  }
  void clear()
  {
    free_nodes();
    head.next = &head;
    head.prev = &head;
  }
  ~List() { free_nodes(); }
};
struct Base0 {
  void **vt;
  int handle;
  int pad8;
  ~Base0()
  {
    vt = DAT_08bb7a48;
    pad8 = 0;
  }
};
struct Base1 : Base0 {
  ~Base1()
  {
    vt = DAT_08bb7ac8;
    if (handle) {
      FUN_08a9df6c(handle);
      handle = 0;
    }
  }
};
struct Owner : Base1 {
  Tree tree;
  int pad2[3];
  List list;
  ~Owner()
  {
    vt = DAT_08bb7b00;
    FUN_0895082c(&tree);
    list.clear();
  }
};
extern "C" void FUN_0895094c(Owner *self)
{
  self->~Owner();
}
// NEAR: destructor with inlined member destructors (tree at +12 with refcounted values, list at +36 cleared then destroyed),
// and a base chain that sets the vtable pointers 0x08bb7ac8 / 0x08bb7a48. This C++ class version (inline base and member
// dtors) is structurally right but 80 words differ: ours keeps &tree and the list head in saved registers from the entry
// (one per use), retail computes the tree address (addiu s3,s2,12) just before the erase loop and passes a0+12 directly
// to the first call. A flat C-style version of the same body was 69 words off.
// near miss from lane lbp9a (unreviewed)
