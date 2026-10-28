/* LBPMATCH module=EBOOT.BIN start=0x089466cc end=0x08946908 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08bef8dc rodata=0x08bab598 */
/* Template instance of src/eboot/static_init_08804948.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its globals live); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
int DAT_08bef8f0 = dyn(9);
int DAT_08bef8ec = dyn(13);
int DAT_08bef8e8 = dyn(25);
int DAT_08bef8e4 = dyn(6);
int DAT_08bef8e0 = dyn(15);
int DAT_08bef8dc = dyn(15);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
static H0 h0;
static H1 h1;
static H2 h2;
