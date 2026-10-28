/* LBPMATCH module=EBOOT.BIN start=0x0889dca4 end=0x0889dd04 symbol=FUN_0889dca4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
/* Placement-copies the 0x18-byte elements [first, last) to dest, one element at a time through FUN_08a9c0b4
   (skipping a null destination slot); returns the end of the destination range. */
struct Elem24 {
  char data[0x18];
};

extern void FUN_08a9c0b4(struct Elem24 *dest, struct Elem24 *src);

struct Elem24 *FUN_0889dca4(struct Elem24 *first, struct Elem24 *last, struct Elem24 *dest)
{
  while (first != last) {
    if (dest != 0) {
      FUN_08a9c0b4(dest, first);
    }
    dest = dest + 1;
    first = first + 1;
  }
  return dest;
}
