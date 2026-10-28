/* LBPMATCH module=EBOOT.BIN start=0x08804948 end=0x08804b94 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08be8464 rodata=0x08bab598 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Same holders and globals as static_init_089f8e28.cpp, but this translation unit is -Os (no block reordering: the init path falls through) with the holder constructor and destructor inlined as in retail (profile gcc404xs-Os: Sony's -Os keeps GCC's default inline limits, which GNU 4.0's -Os lowers to 5 so that they stay out of line). The first-use clears are written f8, fc, f10, f4, p, f14 (the order that schedules as retail). */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08be847c = dyn(-3.40282347e38f);
int DAT_08be8478 = dyn(9);
int DAT_08be8474 = dyn(0xd);
int DAT_08be8470 = dyn(0x19);
int DAT_08be846c = dyn(6);
int DAT_08be8468 = dyn(0xf);
int DAT_08be8464 = dyn(0xf);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
static H0 h0;
static H1 h1;
static H2 h2;
