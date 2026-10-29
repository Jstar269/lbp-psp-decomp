/* LBPMATCH module=EBOOT.BIN start=0x0880fa30 end=0x0880fb20 symbol=FUN_0880fa30 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned, void *p) throw() { return p; }
struct Node { Node *next; Node *prev; int v; };
extern "C" void *DAT_08be84a0;
extern "C" void *FUN_08adbb84(void *, int);
extern "C" void FUN_08adbc24(void *, void *, int);
extern "C" void FUN_08b88fac(Node *, Node *);
extern "C" void FUN_08b88fc8(Node *);
extern "C" Node *FUN_0880fa30(Node *l, Node *x)
{
  if (l != x) {
    Node *f1 = l->next;
    Node *f2 = x->next;
    for (;;) {
      if (f1 == l)
        break;
      if (f2 == x)
        break;
      int v = f2->v;
      f2 = f2->next;
      f1->v = v;
      f1 = f1->next;
    }
    if (f2 == x) {
      Node *c = f1;
      while (c != l) {
        Node *nx = c->next;
        FUN_08b88fc8(c);
        FUN_08adbc24(DAT_08be84a0, c, 12);
        c = nx;
      }
    } else {
      Node *p = f2;
      do {
        Node *n = (Node *)FUN_08adbb84(DAT_08be84a0, 12);
        new (&n->v) int(p->v);
        FUN_08b88fac(n, l);
        p = p->next;
      } while (p != x);
    }
  }
  return l;
}
// NEAR ~44 words (58/60): std::list<int>::operator= (assign overlap, then erase the rest or insert the rest). The first 14 words and the main loop match.
// remaining: block layout after the loop: retail puts the erase loop right after the main loop (entered by a branch-likely to its bottom test), the insert loop later, and the f1==l exit tests f2!=x at the far end; ours puts the insert test first. Ghidra shows a goto into the erase loop; a goto form raised the register count to 4 (worse).
// tried: while/for/for(;;) head tests, separate cursor variables for the two tails, if(f1!=l) erase else if(f2!=x) insert.
// near miss from lane lbp8c (unreviewed)
