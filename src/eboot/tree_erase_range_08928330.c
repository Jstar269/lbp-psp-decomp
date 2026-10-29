/* LBPMATCH module=EBOOT.BIN start=0x08928330 end=0x08928414 symbol=FUN_08928330 lang=c99 */
/* Clone of src/eboot/tree_erase_range_08892970.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Node { int color; struct Node *parent; struct Node *left; struct Node *right; } Node;
typedef struct Tree { int compare; Node header; int count; } Tree;
typedef struct Heap { char pad[32]; int lock; } Heap;
extern Heap *DAT_08be84ac;
extern void FUN_08928168(Tree *);
extern Node *FUN_08b89838(Node *);
extern Node *FUN_08b89b70(Node *, Node *);
extern void FUN_08ad3088(int *);
extern void FUN_08ad2810(int *);
extern void FUN_08adbc24(Heap *, Node *, int);
void FUN_08928330(Tree *t, Node *first, Node *last)
{
  if (first == t->header.left && last == &t->header) {
    FUN_08928168(t);
    return;
  }
  while (first != last) {
    Node *next = FUN_08b89838(first);
    Node *gone = FUN_08b89b70(first, &t->header);
    Heap *h = DAT_08be84ac;
    FUN_08ad3088(&h->lock);
    FUN_08adbc24(h, gone, 24);
    FUN_08ad2810(&h->lock);
    t->count = t->count - 1;
    first = next;
  }
}
