/* LBPMATCH module=EBOOT.BIN start=0x088fcbb4 end=0x088fcc34 symbol=FUN_088fcbb4 lang=c99 rodata=0x08bab59c */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Source {
  void **vtable;
};
struct Sub {
  char pad[0x1a0];
  int zero;
  float step;
};
struct Globals {
  char pad[0x750];
  struct Sub sub;
};
struct Obj {
  char pad0[0x18];
  unsigned char done;
  char pad1[3];
  struct Source *source;
};
extern struct Globals *DAT_08bf7304;
extern const float DAT_08bab5e8; /* 0.2f, shared with the rest of the unit's constant pool */
extern void FUN_08910754(struct Obj *);
extern void FUN_08a50fbc(void);

void FUN_088fcbb4(struct Obj *o)
{
  struct Source *s;
  struct Sub *sub;
  FUN_08910754(o);
  FUN_08a50fbc();
  s = o->source;
  sub = &DAT_08bf7304->sub;
  sub->step = DAT_08bab5e8;
  sub->zero = 0;
  if (s != 0 && ((float (*)(struct Source *))s->vtable[7])(s) >= 1.0f)
    o->done = 1;
}
