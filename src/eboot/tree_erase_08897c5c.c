/* LBPMATCH module=EBOOT.BIN start=0x08897c5c end=0x08897d34 symbol=FUN_08897c5c lang=c99 */
/* Clone of src/eboot/tree_erase_08885280.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Ref { void **vtable; int count; } Ref;
typedef struct Node { int pad[2]; struct Node *left, *right; int pad2[5]; Ref *ref; } Node;
typedef struct Tree { int pad; } Tree;
extern int DAT_08bef8f4;
extern char *DAT_08be84ac;
extern void FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08adbc24(void *, void *, unsigned int);

void FUN_08897c5c(Tree *t, Node *n)
{
  while (n) {
    Ref *r;
    Node *next;
    char *heap;
    FUN_08897c5c(t, n->right);
    r = n->ref;
    next = n->left;
    if (r) {
      int c;
      FUN_08ad3088(&DAT_08bef8f4);
      c = --r->count;
      FUN_08ad2810(&DAT_08bef8f4);
      if (!c) ((void (*)(Ref *))r->vtable[2])(r);
    }
    heap = DAT_08be84ac;
    FUN_08ad3088(heap + 32);
    FUN_08adbc24(heap, n, 40);
    FUN_08ad2810(heap + 32);
    n = next;
  }
}
