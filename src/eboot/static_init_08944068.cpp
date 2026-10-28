/* LBPMATCH module=EBOOT.BIN start=0x08944068 end=0x089449e4 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os rodata=0x08bab598 */
/* Template instance of src/eboot/static_init_08804948.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its globals live); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08bef798, DAT_08bef790, DAT_08bef788, DAT_08bef780, DAT_08bef778, DAT_08bef770, DAT_08beedb8, DAT_08beedb0, DAT_08bee480, DAT_08bedeb8, DAT_08bedeb0, DAT_08bede20, DAT_08bedb30, DAT_08beda48, DAT_08beda40, DAT_08be83e0;
extern Block DAT_08bef858, DAT_08bef840, DAT_08bef828, DAT_08bef810, DAT_08bef7f8, DAT_08bef7e0, DAT_08beee28, DAT_08beee10, DAT_08bee488, DAT_08beded8, DAT_08bedec0, DAT_08bede28, DAT_08bedb38, DAT_08beda98, DAT_08beda80, DAT_08be8400;
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08bef790, DAT_08bef840)
HOLDER(H1, DAT_08bef788, DAT_08bef828)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
HOLDER(H3, DAT_08bedeb0, DAT_08bedec0)
HOLDER(H4, DAT_08bedeb8, DAT_08beded8)
HOLDER(H5, DAT_08beda40, DAT_08beda80)
HOLDER(H6, DAT_08bedb30, DAT_08bedb38)
HOLDER(H7, DAT_08bede20, DAT_08bede28)
HOLDER(H8, DAT_08bee480, DAT_08bee488)
HOLDER(H9, DAT_08beedb8, DAT_08beee28)
HOLDER(H10, DAT_08bef780, DAT_08bef810)
HOLDER(H11, DAT_08beda48, DAT_08beda98)
HOLDER(H12, DAT_08bef778, DAT_08bef7f8)
HOLDER(H13, DAT_08bef770, DAT_08bef7e0)
HOLDER(H14, DAT_08bef798, DAT_08bef858)
HOLDER(H15, DAT_08beedb0, DAT_08beee10)
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
static H14 h14;
static H15 h15;
