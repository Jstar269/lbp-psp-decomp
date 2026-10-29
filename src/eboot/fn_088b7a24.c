/* LBPMATCH module=EBOOT.BIN start=0x088b7a24 end=0x088b7a6c symbol=FUN_088b7a24 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): counter field increment on a looked-up node; exact match verified; names and types await human review. */
struct V { int a; int b; int cnt; };
extern int FUN_088b6374(int, unsigned *);
void FUN_088b7a24(int p, unsigned k)
{
  unsigned key[4];
  int n;
  key[0] = k;
  n = FUN_088b6374(p + 0xa0, key);
  if (n != p + 0xa4) {
    struct V *v = (struct V *)(n + 0x14);
    v->cnt++;
  }
}
