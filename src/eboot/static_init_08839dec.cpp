/* LBPMATCH module=EBOOT.BIN start=0x08839dec end=0x0883a3b0 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08bedaf8 rodata=0x08badf68 */
/* Template instance of src/eboot/static_init_08804948.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its seven globals live; rodata= set by hand to the float constant this copy loads); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08beda60, DAT_08beda58, DAT_08beda50, DAT_08beda48, DAT_08beda40, DAT_08beda38, DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08bedae0, DAT_08bedac8, DAT_08bedab0, DAT_08beda98, DAT_08beda80, DAT_08beda68, DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08bedb10 = dyn(-3.40282347e38f);
int DAT_08bedb0c = dyn(9);
int DAT_08bedb08 = dyn(0xd);
int DAT_08bedb04 = dyn(0x19);
int DAT_08bedb00 = dyn(6);
int DAT_08bedafc = dyn(0xf);
int DAT_08bedaf8 = dyn(0xf);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83e8, DAT_08be8418)
HOLDER(H1, DAT_08be83f0, DAT_08be8430)
HOLDER(H2, DAT_08beda60, DAT_08bedae0)
HOLDER(H3, DAT_08be83e0, DAT_08be8400)
HOLDER(H4, DAT_08beda58, DAT_08bedac8)
HOLDER(H5, DAT_08beda50, DAT_08bedab0)
HOLDER(H6, DAT_08beda48, DAT_08beda98)
HOLDER(H7, DAT_08beda40, DAT_08beda80)
HOLDER(H8, DAT_08beda38, DAT_08beda68)
static H0 h0;
static H1 h1;
static H2 h2;
static H3 h3;
static H4 h4;
static H5 h5;
static H6 h6;
static H7 h7;
static H8 h8;
