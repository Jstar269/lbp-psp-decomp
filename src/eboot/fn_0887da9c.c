/* LBPMATCH module=EBOOT.BIN start=0x0887da9c end=0x0887dacc symbol=FUN_0887da9c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): struct field stores, store order chosen to match scheduling; exact match verified; names and types await human review. */
struct T { int w[0x51]; int a; int b; unsigned char c; };
void FUN_0887da9c(struct T *p, int b, int c, int d, int e)
{
  p->w[2] = b;
  p->w[0] = -1;
  p->w[0xe] = c;
  p->w[0xf] = d;
  p->w[0x10] = e;
  p->a = 0;
  p->b = 0;
  p->c = 0;
  p->w[1] = 0;
  *(unsigned char *)&p->w[0x11] = 0;
}
