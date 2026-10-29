/* LBPMATCH module=EBOOT.BIN start=0x08865bb4 end=0x08865c54 symbol=FUN_08865bb4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 20-byte copy by struct assignment between packed-struct lvalues (member at an aligned offset stores with sw, source loads with lwl/lwr). */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;
extern char DAT_08bafdf0[];
extern char DAT_08bafe24[];
extern void FUN_08879430(void *self, int a, void *fn, int n);
extern void FUN_08864ad8(void);
extern void FUN_08864d5c(void *self, void *src);

typedef struct Obj {
  void *vt0;
  char pad4[8];
  void *vt1;
  char pad10[0x19c - 0x10];
  W5 data;
  int zero;
} Obj;

void FUN_08865bb4(Obj *self, int a, W5 *src)
{
  FUN_08879430(self, a, FUN_08864ad8, 3);
  self->vt0 = DAT_08bafdf0;
  self->vt1 = DAT_08bafe24;
  FUN_08864d5c((char *)self + 200, src);
  self->data = *src;
  self->zero = 0;
}
