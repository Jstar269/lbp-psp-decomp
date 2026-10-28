/* LBPMATCH module=EBOOT.BIN start=0x08999b58 end=0x08999bbc symbol=FUN_08999b58 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern int DAT_08bf5e44;
extern void FUN_08970b6c();
extern void FUN_08999804();
extern void FUN_08999a64();

/* Object with a 16-bit reference count at +6. */
struct RefCounted {
  unsigned char unk_00[6];
  short ref_count;   /* +6 */
};

/* Takes a counted reference to *src, hands it to FUN_08999804, drops the extra reference through
   FUN_08970b6c, then calls FUN_08999a64 with the global and the value 1. */
void FUN_08999b58(int dest, struct RefCounted **src)
{
  struct RefCounted *held[3];   /* only element 0 is used */
  int notify_arg;

  held[0] = *src;
  if (held[0] != 0) {
    held[0]->ref_count = held[0]->ref_count + 1;
  }
  FUN_08999804(dest, held);
  if (held[0] != 0) {
    FUN_08970b6c(held[0]);
  }
  notify_arg = 1;
  FUN_08999a64(DAT_08bf5e44, &notify_arg);
}
