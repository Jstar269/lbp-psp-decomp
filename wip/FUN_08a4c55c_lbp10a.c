/* LBPMATCH module=EBOOT.BIN start=0x08a4c55c end=0x08a4c644 symbol=FUN_08a4c55c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bc5cf0[];
extern char DAT_08bc5cd0[];
extern void FUN_08b9eb88(void *dst, int c, int n);
extern void *FUN_08a9e4a4(int n, int b, int c);
extern void FUN_08b9e7a8(void *dst, const void *src, int n);

typedef struct Obj {
  void *vt;
  int f4;
  char data[20];
  int f1c;
  int f20;
  void *f24;
} Obj;

typedef struct Src {
  char pad[0x14];
  int a;
  int n;
  char more[1];
} __attribute__((packed)) Src;

void FUN_08a4c55c(Obj *self, const Src *src)
{
  self->vt = DAT_08bc5cf0;
  self->f4 = 0;
  self->f1c = 0;
  FUN_08b9eb88(self->data, 0, 20);
  self->vt = DAT_08bc5cd0;
  __builtin_memcpy(self->data, (const char *)src, 20);
  self->f1c = src->a;
  self->f20 = src->n;
  self->f24 = FUN_08a9e4a4(src->n, 0, 0);
  FUN_08b9e7a8(self->f24, src->more, self->f20);
}
// NEAR: ~46 words differ (gcc404xs-O2). Not matched: dest char[20] via memcpy gives retail swl/swr at this+8 with the pointer base, but the source must be an unaligned pointer for the first 20 bytes only
// (later fields src->a, src->n are plain lw): packed Src makes those unaligned too; a (const char *) cast is ignored by __builtin_memcpy; a T20 struct member assignment makes the destination aligned (sw).
// Register roles also differ (retail s2=this, s1=src).
// near miss from lane lbp10a (unreviewed)
