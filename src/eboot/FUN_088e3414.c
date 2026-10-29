/* LBPMATCH module=EBOOT.BIN start=0x088e3414 end=0x088e34f4 symbol=FUN_088e3414 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 20-byte copy by struct assignment between packed-struct lvalues (lwl/lwr + sw); the pointer field is an int, which keeps the store ahead of the loads. */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;

typedef struct Obj {
  char pad0[0x38];
  int type;
  unsigned char flag;
  char pad3d[0x78 - 0x3d];
  W5 data;
  
  int src;
} Obj;

extern int FUN_088e327c(Obj *self, int n, int a, int b);
extern void FUN_088e29c4(Obj *self, W5 *p, Obj *owner);

void FUN_088e3414(Obj *self, W5 *p, int a)
{
  if (!FUN_088e327c(self, 7, a, 0))
    return;
  int t = self->type;
  if ((unsigned)(t - 6) < 3 || t == 15 || t == 16 || t == 18 || t == 20) {
    if (!self->flag) {
      self->src = (int)p;
      self->data = *p;
    }
  }
  FUN_088e29c4(self, p, self);
}
