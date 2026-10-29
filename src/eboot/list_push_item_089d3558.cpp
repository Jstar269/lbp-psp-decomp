/* LBPMATCH module=EBOOT.BIN start=0x089d3558 end=0x089d35c8 symbol=FUN_089d3558 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Rc { short a, b, c; unsigned short count; };
struct Item {
  int a; Rc *b;
  Item(const Item &o) : a(o.a), b(o.b) { if (b) b->count++; }
};
struct Node { int x; int y; Item item; };
inline void *operator new(unsigned, void *p) throw() { return p; }
extern "C" void *DAT_08be84a0;
extern "C" Node *FUN_08adbb84(void *heap, int n);
extern "C" void FUN_08b88fac(Node *n, int list);
extern "C" void FUN_089d3558(int list, Item *src)
{
  Node *n = FUN_08adbb84(DAT_08be84a0, 16);
  new (&n->item) Item(*src);
  FUN_08b88fac(n, list);
}
// placement new on &node->item with a ref-counting copy constructor (null check = addiu 8; beqz).
