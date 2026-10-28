/* LBPMATCH module=EBOOT.BIN start=0x0884c18c end=0x0884c1bc symbol=FUN_0884c18c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Pair {
  int kind;              /* +0 */
  int value;             /* +4 */
};

/* True when kind is 0, or kind is 2 and value is 0x194. */
unsigned int FUN_0884c18c(struct Pair *pair)
{
  unsigned int result;

  result = 1;
  if (pair->kind != 0) {
    if (pair->kind == 2) {
      if (pair->value != 0x194) {
        result = 0;
      }
    }
    else {
      result = 0;
    }
  }
  return result;
}
