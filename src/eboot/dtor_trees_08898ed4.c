/* LBPMATCH module=EBOOT.BIN start=0x08898ed4 end=0x08898fa8 symbol=FUN_08898ed4 lang=c99 */
/* Clone of src/eboot/dtor_trees_088867a0.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); matching idiom: the tree address is kept in a local pointer; exact match verified; names and types await human review. */
struct Node {
  char pad[8];
  struct Node *next;
  struct Node *child;
};
struct Tree {
  char pad[8];
  struct Node *root;
};
struct Pool {
  char pad[32];
  char lock[1];
};
struct Inner {
  char pad[0x10];
  struct Tree tree;
  char pad2[0xc];
  void *buf;
};
struct Outer {
  void *vt;
  int pad[2];
  struct Inner *inner;
  struct Tree tree;
};
extern void *DAT_08bb10c0[];
extern struct Pool *DAT_08be84ac;
extern void FUN_08a9e0c4(void *p);
extern void FUN_08a9e0cc(void *p);
extern void FUN_088864ac(struct Tree *tree, struct Node *n);
extern void FUN_08ad3088(void *lock);
extern void FUN_08ad2810(void *lock);
extern void FUN_08adbc24(struct Pool *pool, void *p, int size);
extern void FUN_08897c5c(struct Tree *tree, struct Node *n);

void FUN_08898ed4(struct Outer *self)
{
  struct Inner *in = self->inner;
  self->vt = DAT_08bb10c0;
  if (in) {
    struct Tree *t = &in->tree;
    if (in->buf) FUN_08a9e0c4(in->buf);
    struct Node *n = t->root;
    while (n) {
      struct Pool *pool;
      struct Node *next;
      FUN_088864ac(t, n->child);
      pool = DAT_08be84ac;
      next = n->next;
      FUN_08ad3088(pool->lock);
      FUN_08adbc24(pool, n, 0x1c);
      FUN_08ad2810(pool->lock);
      n = next;
    }
    FUN_08a9e0cc(in);
  }
  struct Tree *t2 = &self->tree;
  FUN_08897c5c(t2, t2->root);
}
