/* LBPMATCH module=EBOOT.BIN start=0x08aa0aa8 end=0x08aa0ad4 symbol=FUN_08aa0aa8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Copies the 4-byte words in [first, last) to dest and returns the end of the copy (std::copy of words). */
unsigned int *FUN_08aa0aa8(const unsigned int *first, const unsigned int *last, unsigned int *dest)
{
  int count;

  for (count = last - first; 0 < count; count--) {
    *dest++ = *first++;
  }
  return dest;
}
