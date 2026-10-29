/* LBPMATCH module=EBOOT.BIN start=0x089e55cc end=0x089e570c symbol=FUN_089e55cc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef int (*Less)(void *a, void *b);

void FUN_089e55cc(void **first, int top, int len, void *value, Less comp)
{
  int hole = top;
  int child = 2 * hole + 2;
  int parent;
  while (child < len) {
    child -= (comp(first[child], first[child - 1]) != 0);
    first[hole] = first[child];
    hole = child;
    child = 2 * (hole + 1);
  }
  if (child == len) {
    first[hole] = first[child - 1];
    hole = child - 1;
  }
  parent = (hole - 1) / 2;
  while (hole > top && comp(first[parent], value)) {
    first[hole] = first[parent];
    hole = parent;
    parent = (hole - 1) / 2;
  }
  first[hole] = value;
}
// NEAR: libstdc++ __adjust_heap (sift down then push_heap) on an array of pointers with a comparison function; 80/80 words,
// 42 differ. Differences: loop 1 register allocation (retail updates 'child' in place: subu s0,s0,v0; ours allocates a new
// pseudo for the adjusted child) and the layout of the push_heap loop (retail puts its body after the epilogue).
// 'child -= (comp(...) != 0)' is needed (the if (comp()) child-- form gives movz). O2 gives a different frame (91 words).
// A literal Ghidra for(;;) form with break at the top of the loop gave 73 words (no loop rotation).
// near miss from lane lbp9a (unreviewed)
