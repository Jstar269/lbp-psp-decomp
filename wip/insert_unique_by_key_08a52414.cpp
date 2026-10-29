/* LBPMATCH module=EBOOT.BIN start=0x08a52414 end=0x08a524bc symbol=FUN_08a52414 cc=gcc404xs-O2 lang=c++ */
struct Item { int pad; int key; };
struct Node { Node *next; Node *prev; Item *item; };
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b88fac(Node *node, Node *pos);
extern void *DAT_08be84a0;
inline void *operator new(unsigned, void *p) throw() { return p; }

extern "C" int FUN_08a52414(void *param_1, Item *param_2, Node *param_3)
{
  Node *p = param_3->next;
  if (p != param_3) {
    if (p->item->key == param_2->key) return 0;
    for (p = p->next; p != param_3; p = p->next) {
      if (p->item->key == param_2->key) return 0;
    }
  }

  Node *n = (Node *)FUN_08adbb84(DAT_08be84a0, sizeof(Node));
  new (&n->item) Item *(param_2);
  FUN_08b88fac(n, param_3);
  return 1;
}
// 2 words differ: operand order of the two list-sentinel compares (retail beq a0,a2 / beq a0,s0; ours beq a2,a0 / beq s0,a0).
// needs cc=gcc404xs-O2, C++ with a throw() placement new (gives the null check on &node->item), and the first loop iteration written out before the for loop.
// tried: swapped compare sides, local end/last copies, list alias: no change
// near miss from lane lbp3c (unreviewed)
