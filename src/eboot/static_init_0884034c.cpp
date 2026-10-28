/* LBPMATCH module=EBOOT.BIN start=0x0884034c end=0x08840554 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08bedb28 rodata=0x08bab598 */
/* Template instance of src/eboot/static_init_08804948.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its globals live); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08beda48, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08beda98, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08bedb28 = dyn(-3.40282347e+38f);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83e8, DAT_08be8418)
HOLDER(H1, DAT_08be83e0, DAT_08be8400)
HOLDER(H2, DAT_08beda48, DAT_08beda98)
static H0 h0;
static H1 h1;
static H2 h2;
