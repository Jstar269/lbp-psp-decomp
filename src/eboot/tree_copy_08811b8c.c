/* LBPMATCH module=EBOOT.BIN start=0x08811b8c end=0x08811c40 symbol=FUN_08811b8c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { int color; struct Node *parent; struct Node *left; struct Node *right; };
struct Tree { int pad; struct Node header; int count; };
extern void *FUN_08b9eb88(void *, int, int);
extern struct Node *FUN_08811a5c(struct Tree *, struct Node *, struct Node *);
void FUN_08811b8c(struct Tree *self, struct Tree *src)
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
    *root = FUN_08811a5c(self, src->header.parent, h);
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
