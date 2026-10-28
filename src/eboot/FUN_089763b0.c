/* LBPMATCH module=EBOOT.BIN start=0x089763b0 end=0x0897641c symbol=FUN_089763b0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
extern void FUN_08975c1c();   /* tear down the cached object */
extern void FUN_08a9e0cc();   /* free */

struct CachedKind {
  char unk_00[0x14];
  unsigned int cached;       /* +0x14: lazily created object, dropped when the kind changes */
  char unk_18[2];
  unsigned char kind;        /* +0x1a */
};

/* Sets the kind byte. When it changes, the cached object is torn down, freed and cleared.
   Returns 1 if the kind changed, 0 otherwise. */
int FUN_089763b0(struct CachedKind *self, unsigned int kind)
{
  int changed;
  unsigned int cached;

  changed = 0;
  if (self->kind != kind) {
    cached = self->cached;
    if (cached != 0) {
      FUN_08975c1c(cached);
      FUN_08a9e0cc(cached);
    }
    self->kind = (char)kind;
    changed = 1;
    self->cached = 0;
  }
  return changed;
}
