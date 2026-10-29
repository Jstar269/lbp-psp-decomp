/* LBPMATCH module=EBOOT.BIN start=0x088276cc end=0x08827728 symbol=FUN_088276cc lang=c++ */
/* Clone of src/eboot/array_dtor_0880b254.cpp (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Foo { virtual ~Foo(); int pad[43]; };
extern "C" Foo DAT_08bec550[30];
extern "C" void FUN_088276cc(void)
{
  Foo *p = DAT_08bec550 + 30;
  do { --p; p->~Foo(); } while (p != DAT_08bec550);
}
