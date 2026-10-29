/* LBPMATCH module=EBOOT.BIN start=0x0894c704 end=0x0894c75c symbol=FUN_0894c704 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; matching idiom: the non-null result is computed into a local before the stores (otherwise it folds to 1); names and types await human review. */
typedef struct Vt Vt;
typedef struct Obj { Vt *v; int a, b; } Obj;
typedef struct Owner { char pad[168]; Obj *obj; int size; } Owner;
extern Vt DAT_08bb7838;
extern Obj *FUN_08a9e838(int);
extern void FUN_089503ec(Obj *);
int FUN_0894c704(Owner *o)
{
  Obj *n = FUN_08a9e838(12);
  FUN_089503ec(n);
  int ok = n != 0;
  o->size = 12;
  n->v = &DAT_08bb7838;
  o->obj = n;
  return ok;
}
