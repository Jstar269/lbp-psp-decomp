/* LBPMATCH module=EBOOT.BIN start=0x08879808 end=0x08879870 symbol=FUN_08879808 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node {
  int pad0;
  int pad1;
  struct Node *right;
  struct Node *left;
  char key[1];
};
struct Tree {
  int pad;
  int header;
  struct Node *root;
};
extern int FUN_08ba0d98(const char *a, const char *b);

struct Node *FUN_08879808(struct Tree *t, const char *k)
{
  struct Node *x = t->root;
  struct Node *y = (struct Node *)&t->header;
  while (x != 0) {
    if (FUN_08ba0d98(x->key, k) >= 0) {
      y = x;
      x = x->right;
    } else {
      x = x->left;
    }
  }
  return y;
}
