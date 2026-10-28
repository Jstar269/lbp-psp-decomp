/* LBPMATCH module=EBOOT.BIN start=0x08aa39e0 end=0x08aa3a68 symbol=FUN_08aa39e0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
/* Object with a table of virtual functions at its first word; slot 4 is called per index pair. */
struct PairLoopObj {
  void (**vtable)();
  unsigned int inner_count;   /* +4: inner loop bound */
  unsigned int outer_count;      /* +8: outer loop bound */
};

/* Calls virtual slot 4 (+0x10) with (inner, outer, arg) for every index pair, outer index outermost. */
void FUN_08aa39e0(struct PairLoopObj *self, int arg)
{
  unsigned int inner;
  unsigned int outer;

  for (outer = 0; inner = 0, outer < self->outer_count; outer = outer + 1) {
    while (inner < self->inner_count) {
      (*self->vtable[4])(self, inner, outer, arg);
      inner = inner + 1;
    }
  }
}
