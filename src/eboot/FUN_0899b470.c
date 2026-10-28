/* LBPMATCH module=EBOOT.BIN start=0x0899b470 end=0x0899b4f0 symbol=FUN_0899b470 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Releases the first node of the list embedded at +0x1c of `owner`, then continues with one of two follow-ups
   depending on whether the list still has nodes (its sentinel is the member itself). */
struct ListNode0 {
  struct ListNode0 *link0;   /* +0 */
  struct ListNode0 *link4;   /* +4 */
  int payload;               /* +8 */
};

struct ListOwner {
  char pad[0x1c];
  struct ListNode0 list;     /* +0x1c: sentinel node of the list */
};

extern unsigned int DAT_08be84a0;   /* node pool */
extern void FUN_0899b144();
extern void FUN_0899b310();
extern void FUN_08a9bff8();
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

void FUN_0899b470(unsigned int unused, struct ListOwner *owner)
{
  struct ListNode0 *sentinel = &owner->list;
  struct ListNode0 *first;

  first = sentinel->link0;
  FUN_08b88fc8(first);
  FUN_08a9bff8((int)&first->payload);
  FUN_08adbc24(DAT_08be84a0, (unsigned int)first, 0x20);   /* return the 0x20-byte node to the pool */
  if (owner->list.link0 != sentinel) {
    FUN_0899b144(owner);
    return;
  }
  FUN_0899b310(owner);
  return;
}
