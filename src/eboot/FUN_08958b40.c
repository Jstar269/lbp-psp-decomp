/* LBPMATCH module=EBOOT.BIN start=0x08958b40 end=0x08958bf8 symbol=FUN_08958b40 lang=c99 */
/* Clone of src/eboot/FUN_08915108.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  int (**vtable)(struct Obj *, int);
  int pad0;
  int count;
  int pad1[2];
  int lock[1];
};
struct Holder {
  int key;
};
extern void *DAT_08be84a8;
extern struct Obj *FUN_08aaaa80(void *pool, int key);
extern void FUN_08ad3088(int *lock);
extern void FUN_08ad2810(int *lock);
extern void FUN_088050b8(struct Obj *o);

int FUN_08958b40(struct Holder *h, int arg)
{
  int r;
  struct Obj *o = FUN_08aaaa80(DAT_08be84a8, h->key + 16);
  if (o != 0) {
    FUN_08ad3088(o->lock);
    o->count = o->count + 1;
    FUN_08ad2810(o->lock);
    FUN_08ad3088(o->lock);
    o->count = o->count + 1;
    FUN_08ad2810(o->lock);
    FUN_088050b8(o);
  }
  r = o->vtable[4](o, arg);
  FUN_088050b8(o);
  return r;
}
