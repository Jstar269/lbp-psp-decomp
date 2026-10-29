/* LBPMATCH module=EBOOT.BIN start=0x0884c6dc end=0x0884c778 symbol=FUN_0884c6dc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Str {
  char pad[12];
  char data[20];
};
struct Key {
  int pad;
  struct Str *name;
  int num;
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
extern int FUN_08b9e714(const char *a, const char *b, int n);

struct Node *FUN_0884c6dc(struct Tree *t, struct Key *k)
{
  struct Node *result = (struct Node *)t->header;
  struct Node *n = t->root;
  while (n) {
    int less = (k->num == 0 && n->key.num == 0)
                   ? FUN_08b9e714(k->name->data, n->key.name->data, 20) < 0
                   : k->num - n->key.num < 0;
    if (less) {
      result = n;
      n = n->left;
    } else {
      n = n->right;
    }
  }
  return result;
}
// NEAR: upper_bound over a tree keyed by (name string, number); semantics match, 31 words differ by layout only.
// Retail keeps the number test (a0 = key number, reloaded in the loop-back delay slot) and the subu/srl path inline and
// places the memcmp-like call block after the loop exit, jumping back to the shared srl. Ours puts the call block inline.
// Tried: && / || forms, ternary, int vs bool result, cc gcc404xs-O2, gcc171-Os/O2, gcc402x-Os, gcc410-Os.
// near miss from lane lbp9a (unreviewed)
