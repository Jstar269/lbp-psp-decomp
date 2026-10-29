/* LBPMATCH module=EBOOT.BIN start=0x088d5108 end=0x088d5214 symbol=FUN_088d5108 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); NEAR, not verified. */
struct W { int w[59]; };
struct B { char b[236]; };
struct Obj { char pad[224]; char blk[236]; };
extern void FUN_088d4de8();

void FUN_088d5108(struct Obj *t, struct Obj *o)
{
  FUN_088d4de8(t, o);
  if (((unsigned)t->blk | (unsigned)o->blk) & 3) {
    *(struct B *)t->blk = *(struct B *)o->blk;
  } else {
    *(struct W *)t->blk = *(struct W *)o->blk;
  }
}
// NEAR (not measured closely; same class as 0x08af0204/0x08b47240): the original copies 236 bytes at +224 with a runtime (src|dst)&3 test, an unaligned loop (lwl/lwr + swl/swr, 16 bytes per
// iteration, bound = src+448) and an aligned lw/sw loop, then a 12-byte remainder. This compiler emits a single loop per copy and has no runtime dispatch.
// near miss from lane lbp10b (unreviewed)
