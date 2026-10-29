/* LBPMATCH module=EBOOT.BIN start=0x089d88dc end=0x089d8980 symbol=FUN_089d88dc lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern "C" void FUN_089df72c(void *);
extern float DAT_08bab59c;
struct Item {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
  virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
  virtual void act();
  unsigned flags;
};
struct LNode { LNode *next; LNode *prev; Item *item; };
struct Sub { int a; float f; char b; char c[3]; unsigned short s0; unsigned short s1; };
struct Obj {
  virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3();
  virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7();
  virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11();
  virtual void w12(); virtual void w13(); virtual void w14(); virtual void refresh();
  unsigned flags;
  char pad[0x10];
  LNode head;
  char pad2[0x90 - 0x18 - 12];
  Sub sub;
};
extern "C" void FUN_089d88dc(Obj *o)
{
  LNode *end = &o->head;
  FUN_089df72c(o);
  o->refresh();
  for (LNode *n = o->head.next; n != end; n = n->next) {
    Item *it = n->item;
    if (it->flags & 4)
      it->act();
  }
  Sub *s = &o->sub;
  s->b = 0;
  o->flags |= 0x400;
  s->s0 = 0;
  s->f = DAT_08bab59c;
  s->s1 = 0;
}
// NEAR 10 words: C++ with vtable slots 15 (refresh) and 8; list sentinel end=&head must be computed before the first call (done). Retail then does addiu v1,s0,144 AFTER the loop (sub-object pointer in a temp; float@4, byte@8, ushort@12/14) with a 16-byte frame; ours hoists the sub pointer into a callee-saved register (32-byte frame).
// Tried: direct o->sub.x stores, local Sub *s before/after calls, many store orders.
// near miss from lane lbp6d (unreviewed)
