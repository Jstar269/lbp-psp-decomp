/* LBPMATCH module=EBOOT.BIN start=0x08b9b65c end=0x08b9b684 symbol=FUN_08b9b65c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Keyed {
  char pad_00[8];
  unsigned int key;
};

/* Three-way compare of the unsigned keys at +8: 1 when a > b, -1 when a < b, else 0. */
int FUN_08b9b65c(unsigned int unused, struct Keyed *a, struct Keyed *b)
{
  int result;

  result = 1;
  if (a->key <= b->key) {
    result = -1;
    if (b->key <= a->key) {
      result = 0;
    }
  }
  return result;
}
