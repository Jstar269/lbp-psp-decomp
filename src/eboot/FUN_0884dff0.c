/* LBPMATCH module=EBOOT.BIN start=0x0884dff0 end=0x0884e0cc symbol=FUN_0884dff0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 20-byte copy by struct assignment between packed-struct lvalues (member at an aligned offset stores with sw, source loads with lwl/lwr). */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;
extern char DAT_08baed50[];
extern void FUN_0894a258(void *self);
extern const W5 *FUN_08882764(void);

typedef struct Obj {
  void *vt;
  int one;
  int a;
  int b;
  int z10;
  int z14;
  W5 data;
  int z2c;
  int z30;
  char z34;
  char pad35[3];
  int z38[8];
  int c;
} Obj;

void FUN_0884dff0(Obj *self, int a, int b, int c)
{
  FUN_0894a258(self);
  self->one = 1;
  self->a = a;
  self->b = b;
  self->vt = DAT_08baed50;
  self->z10 = 0;
  self->z14 = 0;
  self->data = *FUN_08882764();
  self->z2c = 0;
  self->z30 = 0;
  self->z34 = 0;
  self->z38[0] = 0;
  self->z38[1] = 0;
  self->z38[2] = 0;
  self->z38[3] = 0;
  self->z38[4] = 0;
  self->z38[5] = 0;
  self->c = c;
  self->z38[7] = 0;
  self->z38[6] = 0;
}
