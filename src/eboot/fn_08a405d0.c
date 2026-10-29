/* LBPMATCH module=EBOOT.BIN start=0x08a405d0 end=0x08a4069c symbol=FUN_08a405d0 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): callee FUN_08a352f8 takes four arguments (p4 passed on); two pending values kept in a local pair struct; cc=gcc404xs-O2; exact match verified; names and types await human review. */
struct VT { char pad[0x1c]; void (*f)(void *, int, int, int); };
struct O { struct VT *vt; };
struct S { char pad[400]; struct O *o; int z[2]; unsigned a; unsigned b; };
struct Tmp { unsigned w[6]; };
struct Tmp8 { unsigned w[8]; };
extern void FUN_08a35244(unsigned *, int);
extern void FUN_08a352f8(struct S *, int, int, int);
extern void FUN_08a9bff8(void *);
extern void *FUN_08a9d390(void *, unsigned);
void FUN_08a405d0(struct S *p, int p2, int p3, int p4)
{
  struct { unsigned a, b; } l;
  struct Tmp t1;
  struct Tmp8 t2;
  FUN_08a352f8(p, p2, p3, p4);
  p->o->vt->f(p->o, p2, p3, p4);
  l.a = p->a;
  FUN_08a9d390(&t2, l.a);
  FUN_08a9bff8(&t2);
  l.b = p->b;
  FUN_08a9d390(&t1, l.b);
  FUN_08a9bff8(&t1);
  FUN_08a35244(&l.a, p3);
  FUN_08a35244(&l.b, p3);
  p->a = l.a;
  p->b = l.b;
}
