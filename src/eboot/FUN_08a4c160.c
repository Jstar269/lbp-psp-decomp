/* LBPMATCH module=EBOOT.BIN start=0x08a4c160 end=0x08a4c234 symbol=FUN_08a4c160 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 20-byte copy via __builtin_memcpy into a char[20] member (lwl/lwr + swl/swr). */
extern char DAT_08bc5cf0[];
extern char DAT_08bc5cc0[];
extern void FUN_08b9eb88(void *dst, int c, int n);
extern int FUN_08ba5fa4(void *dst, const char *src, int n);

typedef struct Obj {
  void *vt;
  int f4;
  char data[20];
  int f1c;
  int f20;
  int f24;
  char name[17];
} Obj;

void FUN_08a4c160(Obj *self, const void *src, int a, int b, int mode, const char *str)
{
  self->vt = DAT_08bc5cf0;
  self->f1c = a;
  self->f4 = 0;
  __builtin_memcpy(self->data, src, 20);
  self->vt = DAT_08bc5cc0;
  self->f20 = b;
  self->f24 = mode;
  if (mode == 1) {
    FUN_08ba5fa4(self->name, str, 17);
    self->name[16] = 0;
  } else {
    FUN_08b9eb88(self->name, 0, 17);
  }
}
