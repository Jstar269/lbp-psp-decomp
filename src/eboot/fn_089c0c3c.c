/* LBPMATCH module=EBOOT.BIN start=0x089c0c3c end=0x089c0cf0 symbol=FUN_089c0c3c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): unsigned char parameters; exact match verified; names and types await human review. */
struct S { int a; int *f4; int *f8; int *fc; int *f10; };
extern void FUN_0896b048(int *, int);
void FUN_089c0c3c(struct S *s, unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e)
{
  FUN_0896b048(s->f10, a);
  if (a && b) {
    FUN_0896b048(s->f4, c);
    FUN_0896b048(s->fc, d);
    FUN_0896b048(s->f8, e);
  }
}
