/* LBPMATCH module=EBOOT.BIN start=0x08933d5c end=0x08933dfc symbol=FUN_08933d5c lang=c99 */
/* Clone of src/eboot/FUN_088927c8.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); store order of the four reset stores follows the scheduler (matching idiom); exact match verified; names and types await human review. */
struct Node {
  char pad[8];
  struct Node *next;
  struct Node *child;
};
struct Pool {
  char pad[32];
  char lock[1];
};
struct Tree {
  int pad;
  char header[4];
  struct Node *root;
  void *leftmost;
  void *rightmost;
  int count;
};
extern struct Pool *DAT_08be84ac;
extern void FUN_08933aac(struct Tree *tree, struct Node *n);
extern void FUN_08ad3088(void *lock);
extern void FUN_08ad2810(void *lock);
extern void FUN_08adbc24(struct Pool *pool, void *p, int size);

void FUN_08933d5c(struct Tree *t)
{
  struct Node *n = t->root;
  while (n) {
    struct Pool *pool;
    struct Node *next;
    FUN_08933aac(t, n->child);
    pool = DAT_08be84ac;
    next = n->next;
    FUN_08ad3088(pool->lock);
    FUN_08adbc24(pool, n, 0x18);
    FUN_08ad2810(pool->lock);
    n = next;
  }
  t->count = 0;
  t->leftmost = t->header;
  t->root = 0;
  t->rightmost = t->header;
}
