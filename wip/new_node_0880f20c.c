/* LBPMATCH module=EBOOT.BIN start=0x0880f20c end=0x0880f278 symbol=FUN_0880f20c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Vt Vt;
typedef struct Node { Vt *v; short size; short rc; int a; } Node;
extern Vt DAT_08babc80;
extern void *DAT_08be84a0;
extern void *FUN_08adbb84(void *, int);
Node **FUN_0880f20c(Node **out, int a)
{
  Node *n = FUN_08adbb84(DAT_08be84a0, 16);
  if (n) {
    n->rc = 1;
    n->v = &DAT_08babc80;
    n->a = a;
    n->size = 16;
  }
  *out = n;
  return out;
}
// NEAR 5 words: only the s0/s1 allocation of (out, a) is swapped (ours out=s0 a=s1; retail out=s1 a=s0), stores otherwise identical.
// tried: store orders, local copy of out, static inline init, unsigned arg, long long callee, C++ class with virtual dtor (symbol _ZTV4Node scratch), O2 (worse).
// near miss from lane lbp8c (unreviewed)
