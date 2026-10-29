/* LBPMATCH module=EBOOT.BIN start=0x08a34a70 end=0x08a34adc symbol=FUN_08a34a70 lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/FUN_08a051ec.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the end() sentinel is spelled (char *)t + 4 in the final test, so the compiler does not thread the empty-tree path into the return. */
struct Node {
  int pad0;
  int pad1;
  struct Node *right;
  struct Node *left;
  unsigned int key;
};
struct Tree {
  int pad;
  int header;
  struct Node *root;
};

struct Node *FUN_08a34a70(struct Tree *t, const unsigned int *k)
{
  struct Node *end = (struct Node *)&t->header;
  struct Node *y = end;
  struct Node *x = t->root;
  while (x != 0) {
    if (x->key >= *k) {
      y = x;
      x = x->right;
    } else {
      x = x->left;
    }
  }
  if (y != (struct Node *)((char *)t + 4) && *k >= y->key)
    return y;
  return end;
}
