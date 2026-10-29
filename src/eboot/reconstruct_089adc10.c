/* LBPMATCH module=EBOOT.BIN start=0x089adc10 end=0x089adc4c symbol=FUN_089adc10 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Src;
struct SrcVt { void *slot[3]; float (*eval)(struct Src *, float); };
struct Src { const struct SrcVt *vt; };
struct In { char pad[8]; float value; };
struct Obj { char pad[0x70]; float result; char pad2[140 - 0x74]; struct Src *src; };
extern void FUN_089ada48(struct Obj *);
void FUN_089adc10(struct Obj *o, struct In *in)
{
  o->result = o->src->vt->eval(o->src, in->value);
  FUN_089ada48(o);
}
