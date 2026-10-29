/* LBPMATCH module=EBOOT.BIN start=0x08a85e78 end=0x08a85ecc symbol=FUN_08a85e78 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct T { char pad[0x24c]; int a; int b; int c; char flag; char pad2[3]; float f; } T;
extern void FUN_08a6aed4(T *dst, T *src);
void FUN_08a85e78(T *dst, T *src)
{
  FUN_08a6aed4(dst, src);
  int a = src->a, b = src->b, c = src->c;
  float f = src->f;
  dst->a = a;
  dst->f = f;
  dst->b = b;
  dst->c = c;
  dst->flag = 0;
}
// matching idiom: source fields loaded into locals first (load order); stores a,f,b,c.
