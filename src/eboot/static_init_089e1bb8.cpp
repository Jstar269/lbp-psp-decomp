/* LBPMATCH module=EBOOT.BIN start=0x089e1bb8 end=0x089e1e44 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os rodata=0x08bab598 */
/* Template instance of src/eboot/static_init_08804948.cpp (a Hand-written reconstruction), written by wip/t/sigen.py from this function's disassembly (which holders, in which order, and where its globals live); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08bef780, DAT_08bef778, DAT_08beda40, DAT_08be83e0;
extern Block DAT_08bef810, DAT_08bef7f8, DAT_08beda80, DAT_08be8400;
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83e0, DAT_08be8400)
HOLDER(H1, DAT_08beda40, DAT_08beda80)
HOLDER(H2, DAT_08bef780, DAT_08bef810)
HOLDER(H3, DAT_08bef778, DAT_08bef7f8)
static H0 h0;
static H1 h1;
static H2 h2;
static H3 h3;
