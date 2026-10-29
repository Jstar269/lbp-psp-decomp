/* LBPMATCH module=EBOOT.BIN start=0x08873a2c end=0x08873b18 symbol=FUN_08873a2c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Ref { void **vtable; int count; } Ref;
typedef struct Obj {
  const void *vt;
  char pad[212];
  Ref *a;
  Ref *b;
} Obj;
extern char DAT_08bb0578[];
extern char DAT_08bef8f4[];
extern void FUN_08ad3088(void *);
extern void FUN_08ad2810(void *);

static inline void release(Ref *r)
{
  int c;
  if (r != 0) {
    FUN_08ad3088(DAT_08bef8f4);
    c = --r->count;
    FUN_08ad2810(DAT_08bef8f4);
    if (c == 0) ((void (*)(Ref *))r->vtable[1])(r);
  }
}

void FUN_08873a2c(Obj *self)
{
  self->vt = DAT_08bb0578;
  release(self->b);
  release(self->a);
}
