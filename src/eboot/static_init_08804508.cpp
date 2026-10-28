/* LBPMATCH module=EBOOT.BIN start=0x08804508 end=0x08804764 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08be8448 rodata=0x08bab598 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The static-init holder template (src/eboot/static_init_08804948.cpp, -Os, written out by wip/t/sigen.py) plus one object defined first with init_priority(101) whose inline destructor calls abort (retail: the destruction path tests priority 101 after 65535 and calls abort). */
extern "C" void FUN_08adb8a4(void *p);
extern "C" void abort(void);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08be8430, DAT_08be8418, DAT_08be8400;
struct Fatal { ~Fatal() { abort(); } };
static Fatal fatal __attribute__((init_priority(101)));
template <class T> inline T dyn(T v) { return v; }
int DAT_08be8460 = dyn(9);
int DAT_08be845c = dyn(0xd);
int DAT_08be8458 = dyn(0x19);
int DAT_08be8454 = dyn(6);
int DAT_08be8450 = dyn(0xf);
int DAT_08be844c = dyn(0xf);
float DAT_08be8448 = dyn(-3.40282347e38f);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
static H0 h0;
static H1 h1;
static H2 h2;
