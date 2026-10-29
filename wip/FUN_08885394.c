/* LBPMATCH module=EBOOT.BIN start=0x08885394 end=0x0888542c symbol=FUN_08885394 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Key {
  int a;
  unsigned b;
};
struct Node {
  int pad[2];
  struct Node *left;
  struct Node *right;
  struct Key key;
};
struct Tree {
  int pad;
  char header[4];
  struct Node *root;
};

struct Node *FUN_08885394(struct Tree *t, struct Key *k)
{
  struct Node *header = (struct Node *)t->header;
  struct Node *y = header;
  struct Node *x = t->root;
  struct Node *ret;
  while (x) {
    if (!(x->key.a < k->a || (x->key.a == k->a && x->key.b < k->b))) {
      y = x;
      x = x->left;
    } else {
      x = x->right;
    }
  }
  ret = header;
  if (y != header) {
    if (y->key.a <= k->a) {
      ret = y;
      if (k->a == y->key.a) {
        ret = header;
        if (y->key.b <= k->b) ret = y;
      }
    }
  }
  return ret;
}
// NEAR: map find over a (int, unsigned) key; semantics match, 32 words differ (layout + register roles).
// Retail: header in t1, y in a0 (updated through a branch-likely delay slot), result in a2, key address (node+16) in t0;
// the y = x block is out of line after the loop. Tried: pair-style less(), if/else order swaps, lower_bound then
// !(k < y) tail, cc gcc404xs-O2.
// near miss from lane lbp9a (unreviewed)
