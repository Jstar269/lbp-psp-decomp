/* LBPMATCH module=EBOOT.BIN start=0x089df2b8 end=0x089df400 symbol=FUN_089df2b8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Pool {
  char pad[32];
  char lock[1];
};
struct Res {
  virtual void v0();
  virtual void release();
  unsigned flags;
};
struct LNode {
  LNode *next;
  LNode *prev;
  Res *res;
};
struct Owner {
  void **vt;
  char pad[0x14];
  LNode head;       /* +0x18 sentinel */
  char pad2[0x1c - 0xc + 0x0];
  Res *a;           /* +0x34 */
  char pad3[4];
  Res *b;           /* +0x3c */
  Res *slots[4];    /* +0x40 */
};
extern "C" void *DAT_08bc1b50[];
extern "C" Pool *DAT_08be84ac;
extern "C" void FUN_08ad3088(void *lock);
extern "C" void FUN_08ad2810(void *lock);
extern "C" void FUN_08adbc24(Pool *pool, void *p, int size);
extern "C" void FUN_0896b250(Owner *self);

extern "C" void FUN_089df2b8(Owner *self)
{
  self->vt = DAT_08bc1b50;
  if (self->b) self->b->release();
  if (self->a) self->a->release();
  LNode *end = &self->head;
  for (LNode *n = self->head.next; n != end; n = n->next) {
    Res *r = n->res;
    if (((unsigned *)r)[1] & 0x2000) {
      if (r) r->release();
    }
  }
  for (int i = 0; i < 4; i++) {
    if (self->slots[i]) self->slots[i]->release();
  }
  LNode *n = self->head.next;
  while (n != &self->head) {
    Pool *pool = DAT_08be84ac;
    LNode *next = n->next;
    FUN_08ad3088(pool->lock);
    FUN_08adbc24(pool, n, 0x14);
    FUN_08ad2810(pool->lock);
    n = next;
  }
  FUN_0896b250(self);
}
// NEAR: 29 words differ, caused by 2 things: retail keeps the end pointer of the first list loop in its own register (s1)
// and recomputes &head for the free loop in a separate register (s5); ours shares one register (hoisted/CSE'd).
// The null check after the flag test needs the ((unsigned*)r)[1] access (a struct member access lets VRP delete it).
// Tried: explicit end locals in both loops, an end() inline member, O2 (88 words, worse).
// near miss from lane lbp9a (unreviewed)
