/* LBPMATCH module=EBOOT.BIN start=0x08b8d0b8 end=0x08b8d0ec symbol=FUN_08b8d0b8 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
/* Reads a variable-length integer (LEB128: 7 bits per byte, low bits first, high bit = more bytes follow).
   Stores the value in *out and returns the pointer just past the last byte read. */
unsigned char *FUN_08b8d0b8(unsigned char *src, unsigned int *out)
{
  unsigned char byte;
  unsigned int shift = 0;
  unsigned int value = 0;

  do {
    byte = *src;
    src = src + 1;
    value = value | (byte & 0x7f) << (shift & 0x1f);
    shift = shift + 7;
  } while ((char)byte < 0);
  *out = value;
  return src;
}
