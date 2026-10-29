/* LBPMATCH module=EBOOT.BIN start=0x0885391c end=0x08853a4c symbol=FUN_0885391c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified (the lock is declared as an object, not an array); names and types await human review. */
struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void destroy();
  int refs;
};
struct Node {
  char pad[0x14];
  Obj *obj;
};
struct Pool {
  char pad[32];
  char lock[1];
};
struct Tree {
  char pad[4];
  char header[4];
  Node *root;
  Node *leftmost;
  Node *rightmost;
  int count;
};
struct Lock { int x; };
extern "C" Lock DAT_08bef8f4;
extern "C" Pool *DAT_08be84ac;
extern "C" void FUN_08853830(Tree *t);
extern "C" Node *FUN_08b89838(Node *n);
extern "C" Node *FUN_08b89b70(Node *n, void *header);
extern "C" void FUN_08ad3088(void *lock);
extern "C" void FUN_08ad2810(void *lock);
extern "C" void FUN_08adbc24(Pool *pool, void *p, int size);

extern "C" void FUN_0885391c(Tree *t, Node *first, Node *last)
{
  if (first == t->leftmost && last == (Node *)t->header) {
    FUN_08853830(t);
    return;
  }
  while (first != last) {
    Node *next = FUN_08b89838(first);
    Node *z = FUN_08b89b70(first, t->header);
    Obj *o = z->obj;
    if (o) {
      FUN_08ad3088(&DAT_08bef8f4);
      int r = o->refs - 1;
      o->refs = r;
      FUN_08ad2810(&DAT_08bef8f4);
      if (r == 0) o->destroy();
    }
    Pool *pool = DAT_08be84ac;
    FUN_08ad3088(pool->lock);
    FUN_08adbc24(pool, z, 0x20);
    FUN_08ad2810(pool->lock);
    t->count--;
    first = next;
  }
}
