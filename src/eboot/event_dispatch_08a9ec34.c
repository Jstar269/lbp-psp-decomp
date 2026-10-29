/* LBPMATCH module=EBOOT.BIN start=0x08a9ec34 end=0x08a9eca0 symbol=FUN_08a9ec34 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct S { int a; int b; int c; };
extern struct S DAT_08bf85f8;
extern int FUN_08a9e2a0(void);
extern void FUN_08a9ec34(int param_1,int param_2)
{
  if (param_1 == 1) {
    if (param_2 == 0x66) FUN_08a9eb10(&DAT_08bf85f8);
  } else if (param_1 == 0) {
    if (param_2 == 0x66) {
      DAT_08bf85f8.a = FUN_08a9e2a0();
      FUN_08baa16c(DAT_08bf85f8.b);
    }
  }
}
