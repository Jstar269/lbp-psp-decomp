/* LBPMATCH module=EBOOT.BIN start=0x089e174c end=0x089e17dc symbol=FUN_089e174c lang=c++ */
struct Node { int a; int b; int item; };
inline void *operator new(unsigned, void *p) throw() { return p; }
extern "C" void *DAT_08be84a0;
extern "C" Node *FUN_08adbb84(void *heap, int n);
extern "C" void FUN_08a9e0c4(int v);
extern "C" void FUN_08b88fac(Node *n, int *tail);
extern "C" void FUN_089e174c(int *list, int *slot, int d)
{
  int *tail = list + 3;
  if (*slot != 0) {
    if ((unsigned)(*list - d) < 2) {
      Node *n = FUN_08adbb84(DAT_08be84a0, 12);
      new (&n->item) int(*slot);
      FUN_08b88fac(n, tail);
      *slot = 0;
    } else {
      FUN_08a9e0c4(*slot);
      *slot = 0;
    }
  }
}
// NEAR (8 words): retail computes s1 = list+12 after `lw v0,0(a0)` (inside the *slot!=0 block, before the sltiu); ours hoists addiu s1 above the first beqz (this variant) or sinks it to the call (tail declared inside the block). Placement-new null check form matches. Tried struct list, cur local, tail[-3], O2.
// near miss from lane lbp6b (unreviewed)
