/* LBPMATCH module=EBOOT.BIN start=0x08a6b0ec end=0x08a6b124 symbol=FUN_08a6b0ec lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. Virtual call with this passed, unit is -O2. */
typedef unsigned char uchar;
extern void FUN_08a1d69c(int, uchar);
struct VT { int pad[4]; int (*fn)(void *); };
struct Obj { struct VT *vt; };
struct Owner { char pad[0x188]; struct Obj *obj; };
void FUN_08a6b0ec(struct Owner *param_1, uchar param_2)
{
  struct Obj *o = param_1->obj;
  int r = o->vt->fn(o);
  FUN_08a1d69c(r, param_2);
}
