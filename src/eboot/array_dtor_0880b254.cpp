/* LBPMATCH module=EBOOT.BIN start=0x0880b254 end=0x0880b2b0 symbol=FUN_0880b254 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Foo { virtual ~Foo(); int pad[43]; };
extern "C" Foo DAT_08be8610[30];
extern "C" void FUN_0880b254(void)
{
  Foo *p = DAT_08be8610 + 30;
  do { --p; p->~Foo(); } while (p != DAT_08be8610);
}
