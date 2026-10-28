/* LBPMATCH module=EBOOT.BIN start=0x08843824 end=0x08843854 symbol=FUN_08843824 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Returns the object at +0x20 when either of the two ints that its pointers at +0x18 and +0x14 refer to is
   non-zero, else 0. */
struct Inner {
  char pad[0x14];
  int *flag_a;               /* +0x14 */
  int *flag_b;               /* +0x18 */
};

struct Outer {
  char pad[0x20];
  struct Inner *inner;       /* +0x20 */
};

struct Inner *FUN_08843824(struct Outer *self)
{
  struct Inner *inner;
  struct Inner *result;

  inner = self->inner;
  if ((*inner->flag_b != 0) || (result = 0, *inner->flag_a != 0)) {
    result = inner;
  }
  return result;
}
