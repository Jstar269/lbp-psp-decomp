/* LBPMATCH module=EBOOT.BIN start=0x089f6900 end=0x089f6988 symbol=FUN_089f6900 lang=c99 cc=gcc171-Os rodata=0x08bb2218 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { char pad0[0xc]; int total; char pad1[4]; unsigned char flag; char pad2[3]; float rate; char pad3[8]; int f24; void *f28; };
extern void FUN_0897c25c(void *);
extern void FUN_0897f480(void *);
extern void FUN_08a9bff8(void *);
extern void *FUN_08a9d390(void *, int);
void FUN_089f6900(struct Obj *o)
{
  int tmp[8];
  int v = (int)(o->rate * 100.0f) + o->total;
  o->total = v;
  if (v > 1000000) o->total = 1000000;
  FUN_0897c25c(o->f28);
  o->flag = 0;
  FUN_08a9d390(tmp, -1);
  FUN_08a9bff8(tmp);
  { void *h = o->f28; o->f24 = -1; FUN_0897f480(h); }
}
// 8 words differ at gcc171-Os (gcc404xs/402x/410 are 24+ off): retail loads lui v0,0xf before lw v1,12(a0) and ori a0,v0,0x4240 (constant via v0), puts sb zero in the jal delay slot (after li a1,-1 / move a0,sp) and lw a0,40(s0) before li v0,-1. Tried: ternary-comma, local handle, re-read total; gcc171-O2/gcc171x-Os the same 8.
// near miss from lane lbp6a (unreviewed)
