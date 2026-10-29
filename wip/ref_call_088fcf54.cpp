/* LBPMATCH module=EBOOT.BIN start=0x088fcf54 end=0x088fd00c symbol=FUN_088fcf54 lang=c++ rodata=0x08bab5d8 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Res {
  virtual void v0();
  virtual void v1();
  virtual void release();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void setScale(float f);
  int rc;
};
struct World { char pad[0x24c]; int cam; };
struct Owner { char pad[0x18]; char flag; char pad2[3]; Res *res; };
extern "C" World *DAT_08bf7304;
extern "C" void FUN_0891074c(Owner *);
extern "C" int FUN_08a50fbc();
extern "C" void FUN_08a2f7f8(float, int, Res **, char);
extern "C" void FUN_088fcf54(Owner *o)
{
  FUN_0891074c(o);
  FUN_08a50fbc();
  o->flag = 0;
  World *w = DAT_08bf7304;
  o->res->setScale(0.0f);
  Res *r = o->res;
  int cam = w->cam;
  if (r) r->rc++;
  FUN_08a2f7f8(0.1f, cam, &r, 0);
  if (r && --r->rc == 0)
    r->release();
}
// NEAR 2 words (47/46): everything matches except the float zero argument: ours emits mtc1 zero,$f12 first and a nop in the jalr delay slot; retail puts mtc1 in the jalr delay slot (same as lbp4a 0x088c4f14, lbp6b 0x088fb3e8).
// tried: float local hoisted, receiver local, world load order, O2, gcc171/402x/410. vtable layout: release at slot 2 (+8), setScale at +0x18 (class declared with v0,v1,release,v3,v4,v5,setScale).
// near miss from lane lbp8c (unreviewed)
