/* LBPMATCH module=EBOOT.BIN start=0x08840f64 end=0x08841000 symbol=FUN_08840f64 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Inner { char pad[0x78]; unsigned int limit; };
struct Obj { int state; int pad[6]; struct Inner *inner; };
extern int DAT_08bedb18;
extern void FUN_08908628(struct Inner *);
extern void FUN_08908a48(struct Inner *);
extern void FUN_08908ae4(struct Inner *);
extern int FUN_0892d1bc(int, unsigned int, unsigned int);
extern void FUN_08a9e0cc(struct Inner *);
void FUN_08840f64(struct Obj *param_1, unsigned int param_2)
{
  int r;
  int g = DAT_08bedb18;
  unsigned int lim = param_1->inner->limit;
  unsigned int n = lim > param_2 ? lim - param_2 : 0;
  param_1->state = 2;
  r = FUN_0892d1bc(g, n, param_2);
  if (r == 0) {
    struct Inner *in;
    FUN_08908a48(param_1->inner);
    in = param_1->inner;
    if (in != 0) {
      FUN_08908628(in);
      FUN_08a9e0cc(in);
    }
    param_1->inner = 0;
    param_1->state = 0;
    return;
  }
  FUN_08908ae4(param_1->inner);
}
