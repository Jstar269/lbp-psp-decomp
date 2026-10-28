/* LBPMATCH module=EBOOT.BIN start=0x08b8e248 end=0x08b8e25c symbol=FUN_08b8e248 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Returns 6 when the fifth argument equals the third, otherwise 1. The other arguments are unused. */
unsigned int FUN_08b8e248(unsigned int unused_a, unsigned int unused_b, int arg_c, unsigned int unused_d, int arg_e)
{
  unsigned int result;

  result = 6;
  if (arg_e != arg_c) {
    result = 1;
  }
  return result;
}
