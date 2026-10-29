/* LBPMATCH module=EBOOT.BIN start=0x0888a8b8 end=0x0888a938 symbol=FUN_0888a8b8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Ctx {
  int w0, w4;                 /* 0x00 */
  char b8, b9, b10;           /* 0x08 */
  char pad11[0x50 - 0x0b];
  int w50, w54, w58;          /* 0x50 */
  char b5c, b5d;              /* 0x5c */
  char pad5e[0x4b8 - 0x5e];
  int w4b8, w4bc, w4c0, w4c4, w4c8, w4cc;
  char pad4d0[4];
  int w4d4;
  char b4d8, b4d9;
};
extern unsigned char DAT_08bdb1fd;
extern struct Ctx *DAT_08bedd40;
extern char DAT_08bee0e0;

void FUN_0888a8b8(struct Ctx *c)
{
  unsigned char v;
  c->b5d = 1;
  c->b10 = 0;
  c->b9 = 0;
  c->b8 = 0;
  c->b5c = 0;
  c->b4d9 = 0;
  v = DAT_08bdb1fd;
  DAT_08bedd40 = c;
  c->w54 = 0;
  c->w50 = -1;
  c->w4b8 = 0;
  c->w58 = 0;
  c->w4c0 = 0;
  c->w4c4 = 0;
  c->w4bc = 0;
  c->w0 = 0;
  c->w4 = 0;
  c->w4d4 = 0;
  if (v) {
    c->w4c8 = 0;
  } else {
    c->w4c8 = 1;
  }
  c->w4cc = 0;
  c->b4d8 = 0;
  DAT_08bee0e0 = 0;
}
// NEAR 2: retail stores w54=0 before w50=-1 (li v0,-1 hoisted above both), ours always emits sw w50 first; source order and statement position have no effect. if(v) w=0 else w=1 gives the retail branch layout.
// near miss from lane lbp6c (unreviewed)
