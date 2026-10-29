/* LBPMATCH module=EBOOT.BIN start=0x0884cec0 end=0x0884cfbc symbol=FUN_0884cec0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Name {
  char pad[12];
  char text[20];
};
struct Key {
  int pad;
  struct Name *name;
  int n;
};
struct Node {
  int pad0;
  int pad1;
  struct Node *right;
  struct Node *left;
  struct Key key;
};
struct Tree {
  int pad;
  int header;
  struct Node *root;
};
extern int FUN_08b9e714(const void *a, const void *b, int n);

static inline int less(const struct Key *a, const struct Key *b)
{
  if (a->n != 0 || b->n != 0)
    return a->n - b->n < 0;
  return FUN_08b9e714(a->name->text, b->name->text, 20) < 0;
}

struct Node *FUN_0884cec0(struct Tree *t, struct Key *k)
{
  struct Node *end = (struct Node *)&t->header;
  struct Node *y = end;
  struct Node *x = t->root;
  while (x != 0) {
    if (!less(&x->key, k)) {
      y = x;
      x = x->right;
    } else {
      x = x->left;
    }
  }
  if (y == end || less(k, &y->key))
    return end;
  return y;
}
// NEAR ~48 words at gcc404xs-Os. lower_bound + find over a (name*, n) key; less(a,b) = (a.n||b.n) ? a.n-b.n<0 : memcmp(name+12,name+12,20)<0.
// Retail keeps the memcmp arm out of line (jumps back into the shared 'srl 31; bnezl' join) and returns y or end through
// two copies of the epilogue; ours merges the results with movz. Tried: O2, (char*)t+4 spelling of end(), _Bool/unsigned result, arm order.
// near miss from lane lbp9b (unreviewed)
