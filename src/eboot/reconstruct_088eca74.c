/* LBPMATCH module=EBOOT.BIN start=0x088eca74 end=0x088ecb2c symbol=FUN_088eca74 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Tmp { int a; int b; int c[5]; };
extern void *DAT_08be85fc;
extern void *DAT_08bf03b8;
extern void FUN_088cc71c(int *);
extern void FUN_088e68a0(void *, int, int);
extern void FUN_088ec8f4(void **, int, struct Tmp *);
extern void FUN_0896fbd4(void *, void **, int, int);
extern void FUN_08970b6c(void *);
extern void *FUN_08970dbc(void *, int);
extern void FUN_0897633c(struct Tmp *, void *);
void FUN_088eca74(void *param_1, unsigned char param_2, int param_3)
{
  void *p;
  struct Tmp t;
  if (param_2 != 0) {
    void *g = DAT_08bf03b8;
    FUN_0897633c(&t, FUN_08970dbc(DAT_08be85fc, param_3));
    FUN_088ec8f4(&p, 0x61ab, &t);
    FUN_0896fbd4(g, &p, 1, 0x19);
    if (p != 0) FUN_08970b6c(p);
    FUN_088cc71c(t.c);
  }
  FUN_088e68a0(param_1, param_2, 0x19);
}
