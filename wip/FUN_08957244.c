/* LBPMATCH module=EBOOT.BIN start=0x08957244 end=0x08957334 symbol=FUN_08957244 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); NEAR, not verified; names and types await human review. */
struct Obj { void (**vt)(struct Obj *); int refc; char blk[20]; int tail; };
struct Cb { char pad0[8]; int arg; void (*notify)(struct Obj **, int); void (*create)(struct Obj **); };
struct Self { int pad; char *base; };

void FUN_08957244(struct Self *self, int off, struct Cb *cb)
{
  struct Obj *r;
  cb->create(&r);
  const char *src = off + self->base;
  __builtin_memcpy(r->blk, src, 20);
  r->tail = *(const int *)(src + 20);
  if (cb->notify) cb->notify(&r, cb->arg);
  if (r) {
    if (--r->refc == 0) r->vt[1](r);
  }
}
// NEAR (about 29 words, register allocation only): the unaligned 20-byte copy and every call match; ours puts `self` in s0 and `off` in s1,
// retail has s1=self, s0=off (so retail's `addu s0,s0,v0` reuses off's register for the source pointer and the tail load is `lw v1,20(s0)`).
// The 20-byte block must be a `char blk[20]` member (a packed struct / struct-of-char member still copies with plain lw/sw because GCC takes
// the alignment from the enclosing object); `(char*)r + 8` memcpy also gave aligned stores. Tried: operand order of off + base, tail first, unsigned off.
// near miss from lane lbp10b (unreviewed)
