/* LBPMATCH module=EBOOT.BIN start=0x0887977c end=0x08879808 symbol=FUN_0887977c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Node { int color; struct Node *parent; struct Node *left; struct Node *right; char key[1]; } Node;
typedef struct Tree { int pad; Node hdr; } Tree;
extern int FUN_08ba0d98(const char *, const char *);
Node *FUN_0887977c(Tree *t, const char *key)
{
  Node *end = &t->hdr;
  Node *x = t->hdr.parent;
  Node *y = end;
  while (x != 0) {
    if (!(FUN_08ba0d98(x->key, key) < 0)) {
      y = x;
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return (y == end || FUN_08ba0d98(key, y->key) < 0) ? end : y;
}
// NEAR 17 words (35/35): retail keeps the loop node in one register (lw s0,12(s0) in the bltzl delay slot; move s1,s0; lw s0,8(s0)) and key in s2 / end copy in s3; ours uses a v0 temp for the loaded child and swaps s2/s3.
// tried: Ghidra next/node shape, res variable, ternary vs if for the final test, continue form, local for left child, O2, gcc171-Os.
// near miss from lane lbp8c (unreviewed)
