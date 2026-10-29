/* LBPMATCH module=EBOOT.BIN start=0x088b83c8 end=0x088b849c symbol=FUN_088b83c8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified (the lock is declared as an object, not an array, and the reset stores follow the scheduler order); names and types await human review. */
struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void destroy();
  int refs;
};
struct Node {
  char pad[8];
  Node *next;
  Node *child;
  int pad2;
  Obj *obj;
};
struct Pool {
  char pad[32];
  char lock[1];
};
struct Tree {
  int pad;
  char header[4];
  Node *root;
  void *leftmost;
  void *rightmost;
  int count;
};
struct Lock { int x; };
extern "C" Lock DAT_08bef8f4;
extern "C" Pool *DAT_08be84a0;
extern "C" void FUN_088b8160(Tree *t, Node *n);
extern "C" void FUN_08ad3088(Lock *lock);
extern "C" void FUN_08ad2810(Lock *lock);
extern "C" void FUN_08adbc24(Pool *pool, void *p, int size);

extern "C" void FUN_088b83c8(Tree *t)
{
  Node *n = t->root;
  while (n) {
    FUN_088b8160(t, n->child);
    Obj *o = n->obj;
    Node *next = n->next;
    if (o) {
      FUN_08ad3088(&DAT_08bef8f4);
      int r = o->refs - 1;
      o->refs = r;
      FUN_08ad2810(&DAT_08bef8f4);
      if (r == 0) o->destroy();
    }
    FUN_08adbc24(DAT_08be84a0, n, 0x18);
    n = next;
  }
  t->count = 0;
  t->leftmost = t->header;
  t->root = 0;
  t->rightmost = t->header;
}
