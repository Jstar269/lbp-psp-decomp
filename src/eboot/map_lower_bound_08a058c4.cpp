/* LBPMATCH module=EBOOT.BIN start=0x08a058c4 end=0x08a05908 symbol=FUN_08a058c4 lang=c++ cc=gcc404xs-O2 */
/* Clone of src/eboot/map_lower_bound_089ed8c8.cpp (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" Node *FUN_08a058c4(Tree *t, const unsigned &k)
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
