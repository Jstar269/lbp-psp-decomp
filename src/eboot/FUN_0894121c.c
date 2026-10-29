/* LBPMATCH module=EBOOT.BIN start=0x0894121c end=0x08941338 symbol=FUN_0894121c lang=c99 */
/* Clone of src/eboot/FUN_08940f30.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Slice {
  int ptr;
  int len;
};
struct Name {
  int ptr;
  int len;
  long long rest[3];
};
struct Res {
  void **vtable;
  char pad[0xa4];
  int a8;
  int ac;
};
extern void *DAT_08bb6dd0[];
extern void *DAT_08be84a8;
extern void FUN_08a9c304(struct Name *dst, struct Slice *src);
extern void FUN_08aaa9a0(struct Name *n);
extern unsigned int FUN_08a9d790(struct Slice *s);
extern int FUN_08aaa780(unsigned int *h);
extern struct Res *FUN_08a9e838(unsigned int size);
extern void FUN_08839938(struct Res *mem, unsigned int h);
extern unsigned int FUN_08aaa924(void *pool, struct Res *r);
extern void FUN_08a9bff8(struct Name *n);

struct Res **FUN_0894121c(struct Res **out, struct Slice *key)
{
  struct Res *obj = 0;
  unsigned int c;
  struct Slice d, b, a;
  struct Name n;
  unsigned int h;
  a.len = key->len;
  a.ptr = key->ptr;
  FUN_08a9c304(&n, &a);
  FUN_08aaa9a0(&n);
  b.ptr = n.ptr;
  b.len = n.len;
  c = FUN_08a9d790(&b);
  if (!FUN_08aaa780(&c)) {
    d.ptr = n.ptr;
    d.len = n.len;
    h = FUN_08a9d790(&d);
    obj = FUN_08a9e838(0xb0);
    FUN_08839938(obj, h);
    obj->vtable = DAT_08bb6dd0;
    obj->ac = 0x60;
    obj->a8 = 0;
    if (!(((int (*)(struct Res *))DAT_08bb6dd0[3])(obj) && FUN_08aaa924(DAT_08be84a8, obj) != 0)) {
      ((void (*)(struct Res *))obj->vtable[1])(obj);
      obj = 0;
    }
  }
  *out = obj;
  FUN_08a9bff8(&n);
  return out;
}
