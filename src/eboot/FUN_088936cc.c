/* LBPMATCH module=EBOOT.BIN start=0x088936cc end=0x08893734 symbol=FUN_088936cc lang=c99 */
/* Clone of src/eboot/FUN_08879808.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
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

struct Node *FUN_088936cc(struct Tree *t, const char *k)
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
