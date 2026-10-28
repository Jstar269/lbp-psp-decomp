/* LBPMATCH module=EBOOT.BIN start=0x089f8e28 end=0x089f9078 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-O2 bss=0x08bf3a20 rodata=0x08bab598 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. C++ static initialisation of three ref-counted holders (64-bit counts; the last release frees the block through FUN_08adb8a4) and seven globals initialised at run time (dyn() keeps them dynamic, as retail stores them here). The first-use clears are written f8, fc, f10, f4, p, f14: that order is the only one found that schedules as retail. Needs GCC 4.0.3+ (gcc404x tests __initialize_p before __priority). */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08bf3a38 = dyn(-3.40282347e38f);
int DAT_08bf3a34 = dyn(9);
int DAT_08bf3a30 = dyn(0xd);
int DAT_08bf3a2c = dyn(0x19);
int DAT_08bf3a28 = dyn(6);
int DAT_08bf3a24 = dyn(0xf);
int DAT_08bf3a20 = dyn(0xf);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
static H0 h0;
static H1 h1;
static H2 h2;
