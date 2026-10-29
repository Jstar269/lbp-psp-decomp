/* LBPMATCH module=EBOOT.BIN start=0x08974c8c end=0x08974d1c symbol=FUN_08974c8c lang=c99 */
/* Clone of src/eboot/dtor_free_objs_array_08974bfc.c (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  void **vt;
};
struct Arr {
  void *vt;
  int pad[2];
  struct Obj **items;
  int count;
};
extern void *DAT_08bbd2a0[];
extern void *DAT_08bab5b8[];
extern void FUN_08a9e0c4(void *p);
void FUN_08974c8c(struct Arr *self)
{
  int i;
  self->vt = DAT_08bbd2a0;
  for (i = 0; i < self->count; i++) {
    struct Obj *o = self->items[i];
    if (o) ((void (*)(struct Obj *))o->vt[1])(o);
  }
  if (self->items) FUN_08a9e0c4(self->items);
  self->vt = DAT_08bab5b8;
}
