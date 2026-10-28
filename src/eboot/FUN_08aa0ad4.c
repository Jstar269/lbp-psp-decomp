/* LBPMATCH module=EBOOT.BIN start=0x08aa0ad4 end=0x08aa0b14 symbol=FUN_08aa0ad4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
extern void *FUN_08b9e8cc(void *dest, const void *src, unsigned int count);   /* memmove(dest, src, byte_count) */

/* Moves the bytes in [first, last) to dest and returns dest + length. */
char *FUN_08aa0ad4(char *first, char *last, char *dest)
{
  FUN_08b9e8cc(dest, first, last - first);
  return dest + (last - first);
}
