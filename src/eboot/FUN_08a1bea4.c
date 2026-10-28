/* LBPMATCH module=EBOOT.BIN start=0x08a1bea4 end=0x08a1bed0 symbol=FUN_08a1bea4 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#define TOP_BIT 0x80000000

/* Packs the five fields at bit offsets 24, 16, 20, 0 and 8 and sets bit 31. */
unsigned int FUN_08a1bea4(int field_24, int field_16, int field_20, unsigned int field_0, int field_8)
{
  return field_24 << 0x18 | field_16 << 0x10 | field_20 << 0x14 | field_0 | field_8 << 8 | TOP_BIT;
}
