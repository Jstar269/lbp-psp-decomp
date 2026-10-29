/* LBPMATCH module=EBOOT.BIN start=0x088e4e9c end=0x088e4fc8 symbol=FUN_088e4e9c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10b, Sonnet 5.5); NEAR, not verified; names and types await human review. */
struct PB { int w[5]; } __attribute__((packed));
struct T { char pad0[28]; int f28; char pad1[24]; int type; char pad2[27]; unsigned char b87; char pad3[32]; int w120, w124, w128, w132, w136; char *p140; };
struct G { char pad[0x1ce]; unsigned char flag; };
extern int DAT_08bb440c;
extern struct G *DAT_08beed14;
extern void FUN_088e40c0();
extern int FUN_088e3e74();
extern void FUN_088e29c4();

int FUN_088e4e9c(struct T *t)
{
  int type = t->type;
  if ((unsigned)(type - 6) < 3 || type == 15 || type == 16 || type == 18 || type == 20) {
    if (t->b87 == 0) return 0;
    t->b87 = 0;
    if (t->f28 == 14) {
      FUN_088e40c0(t, t->p140, 1);
    } else {
      if (t->f28 != 17) return 0;
      char *p = t->p140;
      if (FUN_088e3e74(t, 16, 1, DAT_08bb440c)) {
        t->p140 = p;
        struct PB *q = (struct PB *)p;
        int e = q->w[4];
        int a = q->w[0];
        int b = q->w[1];
        int c = q->w[2];
        int d = q->w[3];
        t->w120 = a;
        t->w124 = b;
        t->w128 = c;
        t->w132 = d;
        t->w136 = e;
        FUN_088e29c4(t, p, &t->f28);
      }
    }
    DAT_08beed14->flag = 1;
    return 1;
  }
  return 0;
}
// NEAR 6 words (best of a 240-variant brute force over load and store order: loads of w[4] first, then w[0..3], stores in order) -- scheduling only: logic, layout, the 20-byte unaligned read (struct PB packed, locals then field stores) all match. In ours the word-0 lwl/lwr pair is scheduled LAST (lwl 7,11,15,19,3 / lwr 4,8,12,16,0, sw 124 before 120);
// retail has it first (lwl 3,7,11,15,19 / lwr 0,4,8,12,16, sw 120,124,...). Source order of the five loads/stores (incl. rotated and reversed), a packed struct copy via temp, and
// __builtin_memcpy(&t->blk, p, 20) (which materialises s1+120 in t2 and stores through it) were all tried.
// near miss from lane lbp10b (unreviewed)
