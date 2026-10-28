/* LBPMATCH module=EBOOT.BIN start=0x08956438 end=0x08956684 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08befa34 rodata=0x08bab598 */
/* Clone of src/eboot/static_init_08804948.cpp (lbpclone.py tag c8): addresses substituted, and the header's bss= rebased by hand to this copy's lowest global (lbpclone.py keeps the exemplar's); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08befa4c = dyn(-3.40282347e38f);
int DAT_08befa48 = dyn(9);
int DAT_08befa44 = dyn(0xd);
int DAT_08befa40 = dyn(0x19);
int DAT_08befa3c = dyn(6);
int DAT_08befa38 = dyn(0xf);
int DAT_08befa34 = dyn(0xf);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
static H0 h0;
static H1 h1;
static H2 h2;
