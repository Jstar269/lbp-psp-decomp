/* LBPMATCH module=EBOOT.BIN start=0x08a1dd1c end=0x08a1dd70 symbol=FUN_08a1dd1c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Vec { int *b; int *e; int *c; } Vec;
typedef struct O { char pad[6]; unsigned char cur; char pad2; Vec v[2]; } O;
extern int *FUN_08a1dbf0(Vec *v, int *b, int *e);
void FUN_08a1dd1c(O *o)
{
  char *base = (char *)o + o->cur * 12;
  Vec *v = (Vec *)(base + 8);
  FUN_08a1dbf0(v, v->b, v->e);
  o->cur = 1 - o->cur;
}
// matching idiom: byte-pointer base (o + cur*12) then +8; indexing v[cur] folds the +8 first.
