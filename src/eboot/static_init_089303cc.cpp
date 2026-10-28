/* LBPMATCH module=EBOOT.BIN start=0x089303cc end=0x08930c30 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08bef8d0 rodata=0x08bab598 */
/* Template instance of src/eboot/static_init_08804948.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its globals live); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08bef898, DAT_08bef890, DAT_08bef780, DAT_08bef778, DAT_08bee5e0, DAT_08bedeb8, DAT_08bedeb0, DAT_08bedb30, DAT_08beda58, DAT_08beda50, DAT_08beda48, DAT_08beda40, DAT_08beda38, DAT_08be83e0;
extern Block DAT_08bef8b8, DAT_08bef8a0, DAT_08bef810, DAT_08bef7f8, DAT_08bee614, DAT_08beded8, DAT_08bedec0, DAT_08bedb38, DAT_08bedac8, DAT_08bedab0, DAT_08beda98, DAT_08beda80, DAT_08beda68, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08bef8d0 = dyn(-3.40282347e+38f);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08beda38, DAT_08beda68)
HOLDER(H1, DAT_08bef898, DAT_08bef8b8)
HOLDER(H2, DAT_08bef890, DAT_08bef8a0)
HOLDER(H3, DAT_08bee5e0, DAT_08bee614)
HOLDER(H4, DAT_08beda50, DAT_08bedab0)
HOLDER(H5, DAT_08be83e0, DAT_08be8400)
HOLDER(H6, DAT_08bedb30, DAT_08bedb38)
HOLDER(H7, DAT_08beda40, DAT_08beda80)
HOLDER(H8, DAT_08bef780, DAT_08bef810)
HOLDER(H9, DAT_08bef778, DAT_08bef7f8)
HOLDER(H10, DAT_08beda48, DAT_08beda98)
HOLDER(H11, DAT_08beda58, DAT_08bedac8)
HOLDER(H12, DAT_08bedeb0, DAT_08bedec0)
HOLDER(H13, DAT_08bedeb8, DAT_08beded8)
static H0 h0;
static H1 h1;
static H2 h2;
static H3 h3;
static H4 h4;
static H5 h5;
static H6 h6;
static H7 h7;
static H8 h8;
static H9 h9;
static H10 h10;
static H11 h11;
static H12 h12;
static H13 h13;
