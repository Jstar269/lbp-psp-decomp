/* LBPMATCH module=EBOOT.BIN start=0x0897905c end=0x089790ec symbol=FUN_0897905c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  void **vt;
};
struct Arr {
  void *vt;
  int pad[3];
  struct Obj **items;
  int count;
};
extern void *DAT_08bbd8b8[];
extern void *DAT_08bab5b8[];
extern void FUN_08a9e0c4(void *p);
void FUN_0897905c(struct Arr *self)
{
  int i;
  self->vt = DAT_08bbd8b8;
  for (i = 0; i < self->count; i++) {
    struct Obj *o = self->items[i];
    if (o) ((void (*)(struct Obj *))o->vt[1])(o);
  }
  if (self->items) FUN_08a9e0c4(self->items);
  self->vt = DAT_08bab5b8;
}
