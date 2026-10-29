/* LBPMATCH module=EBOOT.BIN start=0x08a915c8 end=0x08a9162c symbol=FUN_08a915c8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct P {
  int pad0[0x60];
  int f180, f184, f188, f18c, f190;
  float f194, f198;
  int f19c, f1a0;
  int pad1[3];
  float f1b0;
  int pad2[2];
  float f1bc;
};
extern void FUN_08a9a5c8(struct P *);
extern void FUN_08a913f0(int *, int *, int *, int *);
extern int *FUN_08a10f1c(void);
extern void FUN_08a115e0(int *, int, int, int, struct P *, int);
void FUN_08a915c8(struct P *p)
{
  FUN_08a9a5c8(p);
  FUN_08a913f0(&p->f180, &p->f184, &p->f188, &p->f18c);
  p->f194 = p->f1b0;
  p->f198 = p->f1bc;
  FUN_08a115e0(FUN_08a10f1c(), p->f19c, p->f1a0, p->f190, p, -1);
}
