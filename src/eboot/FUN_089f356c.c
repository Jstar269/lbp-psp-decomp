/* LBPMATCH module=EBOOT.BIN start=0x089f356c end=0x089f35b8 symbol=FUN_089f356c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Owner {
  char unk_00[0xcc];
  void *unk_cc;                  /* +0xcc: cleared */
};

/* Id handed to both calls of the FUN_089f1a64 / FUN_089f19c0 pair. */
#define PAIR_ID 0x1a

extern unsigned int FUN_089f19c0();
extern void FUN_089f1a64();
extern void FUN_08a9df6c();

/* Releases the allocation held in *slot between the paired FUN_089f1a64 / FUN_089f19c0 calls,
   then clears the owner's field at +0xcc and the slot. */
void FUN_089f356c(unsigned int unused, unsigned int *slot, struct Owner *owner)
{
  FUN_089f1a64(PAIR_ID);
  FUN_08a9df6c(*slot);
  FUN_089f19c0(PAIR_ID);
  owner->unk_cc = 0;
  *slot = 0;
}
