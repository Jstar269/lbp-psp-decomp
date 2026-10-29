/* LBPMATCH module=EBOOT.BIN start=0x08a116a0 end=0x08a116d8 symbol=FUN_08a116a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct V { int pad; int *begin; int *end; } V;
typedef struct O { char pad[0x2010]; V v[4]; } O;
int FUN_08a116a0(O *o)
{
  V *v = o->v;
  int i, sum = 0;
  for (i = 0; i < 4; i++)
    sum += v[i].end - v[i].begin;
  return sum;
}
