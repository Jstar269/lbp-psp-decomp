/* LBPMATCH module=EBOOT.BIN start=0x089f04c8 end=0x089f08e0 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-O2 bss=0x08bf376c rodata=0x08bab598 */
/* Template instance of src/eboot/static_init_089f8e28.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its seven globals live); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08bef898, DAT_08bee5e0, DAT_08beda50, DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08bef8b8, DAT_08bee614, DAT_08bedab0, DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08bf3784 = dyn(-3.40282347e38f);
int DAT_08bf3780 = dyn(9);
int DAT_08bf377c = dyn(0xd);
int DAT_08bf3778 = dyn(0x19);
int DAT_08bf3774 = dyn(6);
int DAT_08bf3770 = dyn(0xf);
int DAT_08bf376c = dyn(0xf);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
HOLDER(H3, DAT_08beda50, DAT_08bedab0)
HOLDER(H4, DAT_08bee5e0, DAT_08bee614)
HOLDER(H5, DAT_08bef898, DAT_08bef8b8)
static H0 h0;
static H1 h1;
static H2 h2;
static H3 h3;
static H4 h4;
static H5 h5;
