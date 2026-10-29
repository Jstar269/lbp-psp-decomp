/* LBPMATCH module=EBOOT.BIN start=0x08875020 end=0x088750f4 symbol=FUN_08875020 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj;
struct Ref {
  Obj *p;
};
struct Pool {
  int pad;
  Obj **items;
  int cap;
  int top;
  int allocated;
};
extern "C" Pool DAT_08beded8;
struct Lock { int x; };
extern "C" Lock DAT_08bef8f4;
extern "C" void FUN_08ad3088(Lock *lock);
extern "C" void FUN_08ad2810(Lock *lock);
extern "C" Obj *FUN_08adb810(int size, int align, int a, int b);
extern "C" void FUN_08945ae8(Obj *o);

extern "C" Ref *FUN_08875020(Ref *out)
{
  Obj *o;
  FUN_08ad3088(&DAT_08bef8f4);
  FUN_08ad3088(&DAT_08bef8f4);
  if (DAT_08beded8.top < DAT_08beded8.cap) {
    o = DAT_08beded8.items[DAT_08beded8.top++];
    if (o) FUN_08945ae8(o);
  } else {
    DAT_08beded8.allocated++;
    o = FUN_08adb810(0x70, 0x10, 0, 0);
    FUN_08945ae8(o);
  }
  FUN_08ad2810(&DAT_08bef8f4);
  out->p = o;
  FUN_08ad2810(&DAT_08bef8f4);
  return out;
}
// NEAR: 28 words differ; one real difference: retail loads the pooled pointer into v0, copies it to s1 (the result) and
// passes v0 to the init call (move s1,v0; move a0,v0), ours loads straight into s1. The lock must be declared as an
// object (struct Lock DAT_08bef8f4, passed as &DAT) to get retail's split lui/addiu addressing. Tried: separate q local
// before/after the init call, goto skip form, inverted if.
// near miss from lane lbp9a (unreviewed)
