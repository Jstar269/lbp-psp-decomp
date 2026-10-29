/* LBPMATCH module=EBOOT.BIN start=0x088bf4bc end=0x088bf53c symbol=FUN_088bf4bc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Vt Vt;
typedef struct Node { Vt *v; short size; short rc; int a; int b; } Node;
extern Vt DAT_08bb3908;
extern void *DAT_08be84a0;
extern void *FUN_08adbb84(void *, int);
Node **FUN_088bf4bc(Node **out, int a, int *p)
{
  Node *n = FUN_08adbb84(DAT_08be84a0, 16);
  if (n) {
    n->a = a;
    n->rc = 1;
    n->v = &DAT_08bb3908;
    n->b = *p;
    n->size = 16;
  }
  *out = n;
  return out;
}
