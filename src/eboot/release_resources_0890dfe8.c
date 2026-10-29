/* LBPMATCH module=EBOOT.BIN start=0x0890dfe8 end=0x0890e0dc symbol=FUN_0890dfe8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct RC { void (**vt)(struct RC *); int refs; };
struct Obj {
  char pad0[0x24]; void *buf;          /* +0x24 */
  char pad1[4]; struct RC *rc;         /* +0x2c */
  void *res30;                         /* +0x30 */
  char pad2[0x48 - 0x34]; int h48;     /* +0x48 */
  unsigned char f4c; char pad3[3];     /* +0x4c */
  int h50;                             /* +0x50 */
  unsigned char f54; char pad4[3];     /* +0x54 */
  void *res58;                         /* +0x58 */
};
extern void FUN_08913e58(void *a, int b);
extern void *FUN_08914a7c(void);
extern void FUN_08916ffc(int h);
extern void FUN_08a1d34c(void *p);
extern void FUN_08a224bc(void *p);
extern void FUN_08a9e0cc(void *p);
extern void FUN_08adb8a4(void *p);

void FUN_0890dfe8(struct Obj *o)
{
  void *p = o->res30;
  if (p) {
    FUN_08a1d34c(p);
    FUN_08a9e0cc(p);
    o->res30 = 0;
  }
  if (o->buf) {
    FUN_08a9e0cc(o->buf);
    o->buf = 0;
  }
  p = o->res58;
  if (p) {
    FUN_08a224bc(p);
    FUN_08a9e0cc(p);
    o->res58 = 0;
  }
  if (o->f4c) {
    FUN_08916ffc(o->h48);
  }
  if (o->f54) {
    FUN_08913e58(FUN_08914a7c(), o->h50);
  }
  struct RC *rc = o->rc;
  if (rc && --rc->refs == 0) {
    (*rc->vt[0])(rc);
    FUN_08adb8a4(rc);
  }
}
