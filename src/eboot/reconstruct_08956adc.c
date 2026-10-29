/* LBPMATCH module=EBOOT.BIN start=0x08956adc end=0x08956b38 symbol=FUN_08956adc lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Sub;
struct SubVt { void *slot[15]; void (*write)(struct Sub *, unsigned int *); };
struct Sub { const struct SubVt *vt; };
struct Obj { int pad; struct Sub sub; };
extern unsigned int *FUN_0894b31c(void *);
extern void FUN_0894b3e4(unsigned int *, int);
void FUN_08956adc(struct Obj *o, void *arg)
{
  unsigned int *p = FUN_0894b31c(arg);
  p[1] = 0x31303056;
  o->sub.vt->write(&o->sub, p);
  FUN_0894b3e4(p, 4);
}
