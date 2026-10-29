/* LBPMATCH module=EBOOT.BIN start=0x08950edc end=0x08950f34 symbol=FUN_08950edc lang=c99 */
/* Clone of src/eboot/ctor_alloc_0894c704.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; matching idiom: the non-null result is computed into a local before the stores (otherwise it folds to 1); names and types await human review. */
typedef struct Vt Vt;
typedef struct Obj { Vt *v; int a, b; } Obj;
typedef struct Owner { char pad[168]; Obj *obj; int size; } Owner;
extern Vt DAT_08bb7b68;
extern Obj *FUN_08a9e838(int);
extern void FUN_089503ec(Obj *);
int FUN_08950edc(Owner *o)
{
  Obj *n = FUN_08a9e838(12);
  FUN_089503ec(n);
  int ok = n != 0;
  o->size = 12;
  n->v = &DAT_08bb7b68;
  o->obj = n;
  return ok;
}
