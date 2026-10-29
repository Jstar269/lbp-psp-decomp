/* LBPMATCH module=EBOOT.BIN start=0x0898d470 end=0x0898d4b0 symbol=FUN_0898d470 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { char pad[0x1c]; void *child; };
extern void FUN_089eec4c(struct Obj *o);
extern void FUN_088a827c(void *p);
extern void FUN_08974360(struct Obj *o);

void FUN_0898d470(struct Obj *o)
{
  FUN_089eec4c(o);
  void *c = o->child;
  o->child = 0;
  if (c) FUN_088a827c(c);
  FUN_08974360(o);
}
