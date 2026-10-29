/* LBPMATCH module=EBOOT.BIN start=0x08a10c14 end=0x08a10c44 symbol=FUN_08a10c14 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): virtual call on o with a passed through; cc=gcc404xs-O2; exact match verified; names and types await human review. */
struct VT { char pad[0x54]; void (*f)(void *); };
struct O { struct VT *vt; };
void *FUN_08a10c14(void *a, struct O *o)
{
  o->vt->f(a);
  return a;
}
