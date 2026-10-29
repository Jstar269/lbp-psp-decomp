/* LBPMATCH module=EBOOT.BIN start=0x088b1b80 end=0x088b1c4c symbol=FUN_088b1b80 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Lock { int x; };
extern "C" void FUN_08ad3088(void *lock);
extern "C" void FUN_08ad2810(void *lock);
struct Shared {
  void **vt;
  int key;
  int refs;
  char pad[8];
  Lock lock;   /* +20 */
  void addref()
  {
    FUN_08ad3088(&lock);
    refs++;
    FUN_08ad2810(&lock);
  }
};
extern "C" void FUN_088050b8(Shared *s);
struct Ref {
  Shared *p;
  Ref(const Ref &o) : p(o.p) { if (p) p->addref(); }
  ~Ref() { if (p) FUN_088050b8(p); }
};
struct Entry {
  int key;
  Ref ref;
};
struct Node;
struct Result {
  Node *it;
  bool ok;
};
struct Owner {
  char pad[20];
  char map[4];   /* +20 */
  char end[4];   /* +24 */
};
extern "C" void *FUN_088b1824(void *map, int *key);
extern "C" Result FUN_0883d904(void *map, Entry *e);

extern "C" void FUN_088b1b80(Owner *self, Ref *h)
{
  int id = h->p->key;
  int probe = id;
  if (FUN_088b1824(self->map, &probe) == self->end) {
    Entry e = { id, *h };
    Result r = FUN_0883d904(self->map, &e);
    Result r2;
    r2.it = r.it;
    r2.ok = r.ok;
  }
}
// NEAR: map insert of (id, ref-counted pointer) when the id is absent; frame size (80) and the Ref copy/addref/release code
// match; 21 words differ: retail keeps the pair<iterator,bool> result in two stack copies (sp+32/36 and a byte-wise copy at
// sp+4/8) and the temporary Entry at sp+12/16, ours places the Entry at sp+4/8 and drops the second copy.
// Needed: a Ref class with copy ctor (addref under the per-object lock at +20) and dtor (call to the release function);
// 'probe' and 'id' as two locals so the key stays in a register while its copy is passed by address.
// near miss from lane lbp9a (unreviewed)
