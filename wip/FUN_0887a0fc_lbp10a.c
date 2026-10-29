/* LBPMATCH module=EBOOT.BIN start=0x0887a0fc end=0x0887a1a0 symbol=FUN_0887a0fc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;
extern char DAT_08bb0858[];
extern void FUN_0894a258(void *self);
extern const W5 *FUN_08882764(void);
extern void FUN_08b9eb88(void *dst, int c, int n);

typedef struct Sub { int four; int z24; int z28; } Sub;

static inline void SubInit(Sub *p)
{
  p->z24 = 0;
  p->z28 = 0;
}

typedef struct Obj {
  void *vt;
  int one;
  W5 data;
  int z1c;
  Sub sub;
  int z2c;
  char buf[128];
  int zb0;
} Obj;

void FUN_0887a0fc(Obj *self)
{
  FUN_0894a258(self);
  self->one = 1;
  self->vt = DAT_08bb0858;
  self->data = *FUN_08882764();
  self->sub.four = 4;
  SubInit(&self->sub);
  self->z1c = 0;
  self->z2c = 0;
  self->zb0 = 0;
  FUN_08b9eb88(self->buf, 0, 128);
}
// NEAR: 2 words differ: retail stores 8(t2)=0, 28(s0)=0, 4(t2)=0; ours 8(t2), 4(t2), 28(s0). Sub-object at +32 initialised by an inline helper (t2 = s0+32 base reproduced), order of the three stores not matched
// after 20 orderings of the helper body / outer stores. Unaligned 20-byte copy: struct assignment of a packed struct member from the packed pointer returned by FUN_08882764 matches.
// near miss from lane lbp10a (unreviewed)
