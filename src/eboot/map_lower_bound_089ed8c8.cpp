/* LBPMATCH module=EBOOT.BIN start=0x089ed8c8 end=0x089ed90c symbol=FUN_089ed8c8 lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. libstdc++ _Rb_tree::lower_bound for unsigned keys; this unit is gcc404xs-O2 (key load hoisted, guarded loop). */
struct Node {
  int pad0;
  int pad1;
  Node *right;
  Node *left;
  unsigned key;
};
struct Tree {
  int pad;
  int header;
  Node *root;
};

extern "C" Node *FUN_089ed8c8(Tree *t, const unsigned &k)
{
  Node *x = t->root;
  Node *y = (Node *)&t->header;
  while (x != 0) {
    if (!(x->key < k)) {
      y = x;
      x = x->right;
    } else {
      x = x->left;
    }
  }
  return y;
}
