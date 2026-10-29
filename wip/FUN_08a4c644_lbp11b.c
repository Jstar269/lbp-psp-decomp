/* LBPMATCH module=EBOOT.BIN start=0x08a4c644 end=0x08a4c794 symbol=FUN_08a4c644 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bc5cf0[];
extern char DAT_08bc5cc0[];
extern void FUN_08b9eb88(void *dst, int c, int n);

typedef struct Obj {
  void *vt;
  int f4;
  char data[20];
  int f1c;
  int f20;
  int f24;
  char name[17];
} Obj;

typedef struct Src {
  char data[20];
  int a;
  int b;
  int mode;
  char name[17];
} Src;

void FUN_08a4c644(Obj *self, const Src *src)
{
  self->vt = DAT_08bc5cf0;
  self->f4 = 0;
  self->f1c = 0;
  FUN_08b9eb88(self->data, 0, 20);
  self->vt = DAT_08bc5cc0;
  __builtin_memcpy(self->data, src->data, 20);
  self->f1c = src->a;
  self->f20 = src->b;
  int mode = src->mode;
  self->f24 = mode;
  if (mode == 1) {
    __builtin_memcpy(self->name, src->name, 17);
    self->name[16] = 0;
  } else {
    FUN_08b9eb88(self->name, 0, 17);
  }
}
// NEAR 3 words: the second vtable address is built in v0 here, in v1 in retail (lui v1 / addiu v1 / sw v1,0(s2)); everything else EXACT.
// Found: copy ctor shape: src and dst have different layouts; `int mode = src->mode; self->f24 = mode; if (mode == 1)` keeps one load (re-reading src->mode after the store gave two loads).
// Tried: second vt store after memcpy / after each later statement (43 words worse), all 6 orders of the three early stores (3 or 5 words).
// near miss from lane lbp11b (unreviewed)
