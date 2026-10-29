/* LBPMATCH module=EBOOT.BIN start=0x088e4020 end=0x088e40c0 symbol=FUN_088e4020 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;

typedef struct Obj {
  char pad0[0x1c];
  char sub[0x78 - 0x1c];
  W5 data;
  int src;
} Obj;

extern int DAT_08bb440c;
extern int FUN_088e3e74(Obj *self, int n, int a, int b);
extern void FUN_088e29c4(Obj *self, W5 *p, char *sub);

void FUN_088e4020(Obj *self, W5 *p, int a)
{
  int g = DAT_08bb440c;
  if (FUN_088e3e74(self, 16, a, g)) {
    self->src = (int)p;
    self->data = *p;
    FUN_088e29c4(self, p, self->sub);
  }
}
// NEAR: 8 words differ (scheduling only). Retail hoists the global load (lui v0; lw a3,17420(v0)) above the stack adjustment; ours places it after the callee-saved spills.
// The body (call, int-typed src store, packed struct assignment, tail call) matches. Tried: local copy of the global, cc=gcc404xs-O2 (31 words).
// near miss from lane lbp10a (unreviewed)
