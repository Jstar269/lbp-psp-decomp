/* LBPMATCH module=EBOOT.BIN start=0x08a5c2a0 end=0x08a5c2f4 symbol=FUN_08a5c2a0 lang=c++ */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): rewritten as C++: heap-allocated list node with throw() placement new on the item member (null check on &node->item), insert before the list's end node; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

struct ListNode { void *next; void *prev; int item; };
inline void *operator new(unsigned, void *p) throw() { return p; }

extern "C" {
extern undefined4 DAT_08be84a0;
extern void *FUN_08adbb84(undefined4, int);
extern void FUN_08b88fac(void *, void *);
}

extern "C" void FUN_08a5c2a0(char *param_1, int param_2)
{
  void *pos = param_1 + 0x20c;
  ListNode *node = (ListNode *)FUN_08adbb84(DAT_08be84a0, 12);
  new (&node->item) int(param_2);
  FUN_08b88fac(node, pos);
}
