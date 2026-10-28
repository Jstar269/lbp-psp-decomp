/* LBPMATCH module=EBOOT.BIN start=0x08b97dbc end=0x08b97e14 symbol=FUN_08b97dbc lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
/* Decodes one signed LEB128 value (7 bits per byte, low group first, high bit = more bytes follow).
   Stores it in *out and returns the pointer past the last byte read. */
unsigned char *FUN_08b97dbc(unsigned char *in, unsigned int *out)
{
  unsigned char byte;
  unsigned int shift = 0;
  unsigned int result = 0;

  do {
    byte = *in;
    in = in + 1;
    result = result | (byte & 0x7f) << shift;
    shift = shift + 7;
  } while ((char)byte < 0);
  if (shift < 0x20 && (byte & 0x40) != 0) {
    result = result | -1 << shift;   /* sign-extend from bit 6 of the last byte */
  }
  *out = result;
  return in;
}
