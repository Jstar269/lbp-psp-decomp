/* LBPMATCH module=EBOOT.BIN start=0x0886cd04 end=0x0886cdb8 symbol=FUN_0886cd04 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void destroy();
  int refs;
};
struct Lock { int x; };
struct Self {
  const void *vt;
  char pad[16];
  Obj *obj;
  char pad1[12];
  void *buf;
  char pad2[4];
  unsigned char flag;
};
extern "C" Lock DAT_08bef8f4;
extern "C" char DAT_08bb03a0[];
extern "C" char DAT_08bb03d0[];
extern "C" void FUN_08a9e0c4(void *);
extern "C" void FUN_08ad3088(void *lock);
extern "C" void FUN_08ad2810(void *lock);
extern "C" void FUN_0894a260(void *);

extern "C" void FUN_0886cd04(Self *self)
{
  self->vt = DAT_08bb03a0;
  if (self->flag && self->buf)
    FUN_08a9e0c4(self->buf);
  Obj *o = self->obj;
  if (o) {
    FUN_08ad3088(&DAT_08bef8f4);
    int r = o->refs - 1;
    o->refs = r;
    FUN_08ad2810(&DAT_08bef8f4);
    if (r == 0) o->destroy();
  }
  self->vt = DAT_08bb03d0;
  FUN_0894a260(self);
}
