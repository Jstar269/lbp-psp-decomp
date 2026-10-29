/* LBPMATCH module=EBOOT.BIN start=0x08825d3c end=0x08825d6c symbol=FUN_08825d3c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct O { char pad[0x14]; float *f; };
float FUN_08825d3c(float x, struct O *o)
{
  float *p = o->f;
  float a = p[0];
  float b = p[1];
  float c = p[2];
  float d = p[3];
  return c + ((d - c) * (x - a)) / (b - a);
}
