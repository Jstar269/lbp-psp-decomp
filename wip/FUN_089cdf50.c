/* LBPMATCH module=EBOOT.BIN start=0x089cdf50 end=0x089ce064 symbol=FUN_089cdf50 lang=c99 rodata=0x08bab59c */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Rc {
  char pad0[8];
  int count;
  char pad1[8];
  int lock[1];
  char pad2[0x90];
  int value;
};
struct Obj {
  void **vtable;
  char pad0[0x18];
  int id;
  struct Rc *ref;
  int value;
  short s0, s1, s2, s3;
  float f;
};
struct Handle {
  struct Rc *rc;
};
extern void *DAT_08bf0380;
extern void *DAT_08bc1368[];
extern void FUN_089d1a10(struct Obj *o);
extern void FUN_089e15dc(void *pool, struct Rc **slot, int v);
extern void FUN_08ad3088(int *lock);
extern void FUN_08ad2810(int *lock);
extern void FUN_088050b8(struct Rc *r);
extern void FUN_089cde38(struct Obj *o);

void FUN_089cdf50(struct Obj *o, struct Handle *h)
{
  struct Rc *r;
  struct Rc *old;
  short *q;
  FUN_089d1a10(o);
  o->vtable = DAT_08bc1368;
  o->id = -1;
  o->f = 1.0f;
  o->value = 0;
  o->ref = 0;
  q = (short *)((char *)o + 40);
  q[2] = 0x7fff;
  q[3] = 0;
  o->s0 = 0;
  q[1] = 0x7fff;
  FUN_089e15dc(DAT_08bf0380, &o->ref, -1);
  r = h->rc;
  if (r != 0) {
    FUN_08ad3088(r->lock);
    r->count = r->count + 1;
    FUN_08ad2810(r->lock);
  }
  old = o->ref;
  o->ref = r;
  if (old != 0)
    FUN_088050b8(old);
  o->value = h->rc != 0 ? h->rc->value : 0;
  if (h->rc != 0)
    FUN_089cde38(o);
}
// NEAR 6 words: only the order of the independent short/int/float stores differs (retail: q[2],q[3],f,ref,value,s0,q[1]); searched all 5040 source orders of the seven stores (best 6 words); not an ordering issue. The three short stores through q = this+40 reproduce retail register assignment.
// near miss from lane lbp9b (unreviewed)
