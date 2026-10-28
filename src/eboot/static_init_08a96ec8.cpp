/* LBPMATCH module=EBOOT.BIN start=0x08a96ec8 end=0x08a97118 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-O2 bss=0x08bf7870 rodata=0x08bab598 */
/* Clone of src/eboot/static_init_089f8e28.cpp (lbpclone.py tag c7): addresses substituted, and the header's bss= rebased by hand to this copy's lowest global (lbpclone.py keeps the exemplar's); exact match verified; names and types await human review. */
extern "C" void FUN_08adb8a4(void *p);
struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };
extern unsigned long long DAT_08be83f0, DAT_08be83e8, DAT_08be83e0;
extern Block DAT_08be8430, DAT_08be8418, DAT_08be8400;
template <class T> inline T dyn(T v) { return v; }
float DAT_08bf7888 = dyn(-3.40282347e38f);
int DAT_08bf7884 = dyn(9);
int DAT_08bf7880 = dyn(0xd);
int DAT_08bf787c = dyn(0x19);
int DAT_08bf7878 = dyn(6);
int DAT_08bf7874 = dyn(0xf);
int DAT_08bf7870 = dyn(0xf);
#define HOLDER(N, COUNT, DATA) \
struct N { N() { if (++COUNT == 1) { DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; } } \
           ~N() { if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); } };
HOLDER(H0, DAT_08be83f0, DAT_08be8430)
HOLDER(H1, DAT_08be83e8, DAT_08be8418)
HOLDER(H2, DAT_08be83e0, DAT_08be8400)
static H0 h0;
static H1 h1;
static H2 h2;
