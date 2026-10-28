/* LBPMATCH module=EBOOT.BIN start=0x089de1a8 end=0x089de1b4 symbol=FUN_089de1a8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

/* Stores a to *out_a and b to *out_b; the output pointers come in the order (out_b, out_a). */
void FUN_089de1a8(unsigned int a, unsigned int b, unsigned int *out_b, unsigned int *out_a)
{
  *out_a = a;
  *out_b = b;
}
