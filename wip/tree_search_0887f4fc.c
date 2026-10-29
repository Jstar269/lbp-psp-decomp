/* LBPMATCH module=EBOOT.BIN start=0x0887f4fc end=0x0887f534 symbol=FUN_0887f4fc lang=c99 */
typedef struct Node { int pad[2]; struct Node *left, *right; int key; } Node;
Node *FUN_0887f4fc(Node *tree, int *key) {
 Node *result = (Node *)((char *)tree + 4), *node = tree->left;
 while (node) {
  Node *next;
  if (node->key < *key) next = node->right;
  else { next = node->left; result = node; }
  node = next;
 }
 return result;
}

// Five branch and scheduling words differ; Os and O2 and typed tree forms tried.
// near miss from lane lbp14a (unreviewed)
