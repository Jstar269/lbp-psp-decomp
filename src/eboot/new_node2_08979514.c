/* LBPMATCH module=EBOOT.BIN start=0x08979514 end=0x08979594 symbol=FUN_08979514 lang=c99 */
/* Clone of src/eboot/new_node2_088bf4bc.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Vt Vt;
typedef struct Node { Vt *v; short size; short rc; int a; int b; } Node;
extern Vt DAT_08bbd900;
extern void *DAT_08be84a0;
extern void *FUN_08adbb84(void *, int);
Node **FUN_08979514(Node **out, int a, int *p)
{
  Node *n = FUN_08adbb84(DAT_08be84a0, 16);
  if (n) {
    n->a = a;
    n->rc = 1;
    n->v = &DAT_08bbd900;
    n->b = *p;
    n->size = 16;
  }
  *out = n;
  return out;
}
