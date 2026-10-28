/* LBPMATCH module=EBOOT.BIN start=0x089de1b4 end=0x089de1c0 symbol=FUN_089de1b4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

/* Stores a to *out_a and b to *out_b (the sibling FUN_089de1a8 takes the output pointers in the other order). */
void FUN_089de1b4(unsigned int a, unsigned int b, unsigned int *out_a, unsigned int *out_b)
{
  *out_b = b;
  *out_a = a;
}
