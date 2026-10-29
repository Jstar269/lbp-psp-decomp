/* LBPMATCH module=EBOOT.BIN start=0x089888e8 end=0x08988934 symbol=FUN_089888e8 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Child;
struct ChildVt { void *slot[58]; void (*destroy)(struct Child *); };
struct Child { const struct ChildVt *vt; };
struct Obj { char pad[0x14]; void *f14; int pad2; struct Child *child; };
extern void FUN_08974360(struct Obj *);
extern void FUN_089a0160(void *);
void FUN_089888e8(struct Obj *o)
{
  if (o->child != 0) {
    o->child->vt->destroy(o->child);
    o->child = 0;
  }
  FUN_089a0160(o->f14);
  FUN_08974360(o);
}
