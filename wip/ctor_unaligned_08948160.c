/* LBPMATCH module=EBOOT.BIN start=0x08948160 end=0x0894826c symbol=FUN_08948160 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct { char b[16]; } B16;
typedef struct Src {
  char *p;
} Src;
typedef struct Obj {
  int pad0;
  int size;
  int f8;
  int fc;
  int f10;
  int f14;
  int f18;
  int f1c;
  char pad20[20];
  int f34;
  char pad38[8];
  char name0[16];
  char name1[24];
  char name2[16];
  char pad78[1384];
  char id[16];
  int pad5f0;
  int f5f4;
} Obj;
extern char *DAT_08bef8d8;
extern void FUN_08b9eb88(void *dst, int c, unsigned n);
extern void FUN_08baa4fc(void *, void *);
extern void FUN_08ba0868(char *dst, int n, const char *src);

void FUN_08948160(Obj *self, Src *src)
{
  int sz = 1536;
  FUN_08b9eb88(&self->size, 0, sz);
  self->size = sz;
  FUN_08baa4fc(&self->f8, &self->fc);
  self->f1c = 31;
  self->f10 = 32;
  self->f18 = 33;
  self->f14 = 34;
  __builtin_memcpy(self->id, src->p + 57, 16);
  FUN_08ba0868(self->name0, 13, DAT_08bef8d8);
  FUN_08ba0868(self->name1, 20, src->p + 24);
  FUN_08ba0868(self->name2, 13, src->p + 44);
  self->f34 = 19;
  self->f5f4 = *(int *)(src->p + 20);
}
// NEAR 5 words: only the scheduling of `self->size = 1536` differs (retail: li v0; addiu a0; addiu a1; jal; sw v0 in the delay slot;
// ours: sw first and addiu a1 in the delay slot). Tried: store after the call (worse), pa/pb locals, int sz local, -O2 (worse).
// Unaligned 16-byte copy = char id[16] member + __builtin_memcpy(self->id, src->p + 57, 16) (a B16 struct assignment gave sw stores).
// near miss from lane lbp11a (unreviewed)
