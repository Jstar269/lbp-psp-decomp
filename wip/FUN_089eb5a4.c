/* LBPMATCH module=EBOOT.BIN start=0x089eb5a4 end=0x089eb6a8 symbol=FUN_089eb5a4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Info {
  int pad;
  int kind;
};
struct Iter {
  struct Info *info;
  int second;
};
struct Self {
  char pad[0x9c];
  int set[1];
};
extern int DAT_08bf92f4;
extern int FUN_08804f34(struct Iter *it) __attribute__((weak));
extern void FUN_088b4a5c(struct Iter *it, int *set);
extern void *FUN_08a9e838(int size);
extern void FUN_088cb720(void *obj);
extern void FUN_0883bd5c(struct Iter *it, void *obj);
extern int FUN_088b3e28(int *set, struct Iter *a, struct Iter *b);
extern void FUN_08804f3c(struct Iter *it);

int FUN_089eb5a4(struct Self *self)
{
  struct Iter b, a;
  int kind;
  void *obj;
  int r;
  FUN_088b4a5c(&a, self->set);
  kind = 0;
  if (a.info != 0 && FUN_08804f34 != 0)
    kind = a.info->kind;
  if (DAT_08bf92f4 == 0 && kind != 0 && kind != 16 && kind != 15 && kind != 8) {
    obj = FUN_08a9e838(20);
    FUN_088cb720(obj);
    FUN_0883bd5c(&b, obj);
    r = FUN_088b3e28(self->set, &a, &b);
    FUN_08804f3c(&b);
    FUN_08804f3c(&a);
    return r;
  }
  FUN_08804f3c(&a);
  return 0;
}
// NEAR ~60 words at gcc404xs-Os (structure right, registers and block order wrong). The `FUN_08804f34 != 0` test is retail's weak-symbol null check (lui/addiu/beqz), reproduced with __attribute__((weak)) on the extern.
// Retail: &a in s1 and the set pointer in s2 held across calls, kind in a0, result in s0 shared by the early-out and success paths, early-outs placed after the main body.
// Tried: local pointers for &a / set, ternary for kind, single result variable with one tail dtor call.
// near miss from lane lbp9b (unreviewed)
