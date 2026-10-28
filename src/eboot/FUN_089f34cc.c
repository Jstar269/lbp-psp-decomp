/* LBPMATCH module=EBOOT.BIN start=0x089f34cc end=0x089f3518 symbol=FUN_089f34cc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Owner {
  char unk_00[0x70];
  void *unk_70;                  /* +0x70: cleared */
};

/* Id handed to both calls of the FUN_089f1a64 / FUN_089f19c0 pair. */
#define PAIR_ID 0x1a

extern unsigned int FUN_089f19c0();
extern void FUN_089f1a64();
extern void FUN_08a9df6c();

/* Releases the allocation held in *slot between the paired FUN_089f1a64 / FUN_089f19c0 calls,
   then clears the owner's field at +0x70 and the slot. */
void FUN_089f34cc(unsigned int unused, unsigned int *slot, struct Owner *owner)
{
  FUN_089f1a64(PAIR_ID);
  FUN_08a9df6c(*slot);
  FUN_089f19c0(PAIR_ID);
  owner->unk_70 = 0;
  *slot = 0;
}
