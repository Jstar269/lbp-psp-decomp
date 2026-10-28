/* LBPMATCH module=EBOOT.BIN start=0x089f631c end=0x089f6324 symbol=FUN_089f631c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g12); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Forwards its seven remaining arguments to FUN_0897cddc, prefixed by the pointer stored at offset 0x28 of self. */
struct Owner89f631c {
  char pad[0x28];
  int target;
};

extern void FUN_0897cddc(int target, unsigned int a1, unsigned int a2, unsigned int a3,
                         unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);

void FUN_089f631c(struct Owner89f631c *self, unsigned int a1, unsigned int a2, unsigned int a3,
                  unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
  FUN_0897cddc(self->target, a1, a2, a3, a4, a5, a6, a7);
}
