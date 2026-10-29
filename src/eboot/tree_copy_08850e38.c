/* LBPMATCH module=EBOOT.BIN start=0x08850e38 end=0x08850eec symbol=FUN_08850e38 lang=c99 */
/* Clone of src/eboot/tree_copy_08811b8c.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { int color; struct Node *parent; struct Node *left; struct Node *right; };
struct Tree { int pad; struct Node header; int count; };
extern void *FUN_08b9eb88(void *, int, int);
extern struct Node *FUN_08850cec(struct Tree *, struct Node *, struct Node *);
void FUN_08850e38(struct Tree *self, struct Tree *src)
{
  struct Node *h = &self->header;
  struct Node *x;
  FUN_08b9eb88(h, 0, 16);
  self->header.parent = 0;
  self->count = 0;
  self->header.color = 0;
  self->header.left = h;
  self->header.right = h;
  if (src->header.parent != 0) {
    struct Node **root = &self->header.parent;
    struct Node **leftmost = &self->header.left;
    struct Node *x;
    *root = FUN_08850cec(self, src->header.parent, h);
    x = *root;
    while (x->left != 0) x = x->left;
    *leftmost = x;
    struct Node **rightmost = &self->header.right;
    x = *root;
    while (x->right != 0) x = x->right;
    *rightmost = x;
    self->count = src->count;
  }
}
