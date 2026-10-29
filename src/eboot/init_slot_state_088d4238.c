/* LBPMATCH module=EBOOT.BIN start=0x088d4238 end=0x088d426c symbol=FUN_088d4238 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { unsigned flags; int p4, p8, p12, p16, p20, p24, p28; int mode; unsigned value; int zero; int pad44, pad48, pad52; unsigned limit; };

void FUN_088d4238(struct Obj *o, unsigned short v)
{
  o->mode = 2;
  o->value = v;
  o->zero = 0;
  if (o->limit == 0) o->limit = 0xffff;
  o->flags &= ~0x30u;
}
