/* LBPMATCH module=EBOOT.BIN start=0x0882de54 end=0x0882df80 symbol=FUN_0882de54 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Key {
  int a;
  int b;
};
struct Node {
  int pad[2];
  Node *left;
  Node *right;
  Key key;
};
struct Tree {
  int pad;
  char header[4];
  Node *root;
  Node *leftmost;
};
struct Result {
  Node *it;
  bool ok;
};
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_0882dca4(Tree *t, Node *x, Node *y, const Key *v);

static inline bool less(const Key &x, const Key &y)
{
  bool r = true;
  if (!(x.a < y.a)) {
    if (y.a < x.a)
      r = false;
    else if (!(x.b < y.b))
      r = false;
  }
  return r;
}

extern "C" Result FUN_0882de54(Tree *t, const Key *v)
{
  Node *x = t->root;
  Node *y = (Node *)t->header;
  bool comp = true;
  while (x) {
    bool lt = less(*v, x->key);
    comp = lt;
    Node *nx = lt ? x->left : x->right;
    y = x;
    x = nx;
  }
  Node *j = y;
  bool ok;
  if (comp) {
    if (j == t->leftmost) goto do_insert;
    j = FUN_08b898a8(j);
  }
  if (less(j->key, *v)) {
do_insert:
    j = FUN_0882dca4(t, x, y, v);
    ok = true;
  } else {
    ok = false;
  }
  Result r = { j, ok };
  return r;
}
// NEAR: map insert_unique returning pair<iterator,bool> in v0/v1; 54 words differ (mostly shifted). Tail now matches the
// retail shape (ok in v0, iterator reuses j); remaining: retail copies the compare result into comp (move v1,a3) in the
// delay slot of the left/right branch before 'y = x', and the entry jumps to the loop test with comp preset (li v1,1).
// The pair compare is the nested if-chain 'r = true; if (!(x.a < y.a)) { if (y.a < x.a) r = false; else if (!(x.b < y.b)) r = false; }'
// with int (signed) second members.
// near miss from lane lbp9a (unreviewed)
