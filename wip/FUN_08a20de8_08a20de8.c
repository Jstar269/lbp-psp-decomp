/* LBPMATCH module=EBOOT.BIN start=0x08a20de8 end=0x08a20e78 symbol=FUN_08a20de8 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

struct G { char pad[0x478]; int f; };
extern struct G *DAT_08be8510;
extern int DAT_08bf5e40;
extern void FUN_088050b8(int*);
extern void FUN_0882321c(int*,int,int);
extern void FUN_08a209d0(int*,int);

void FUN_08a20de8(int *p)
{
  FUN_08a209d0(p, *(int *)(*p + 4));
  int *q = (int *)*p;
  *p = 0;
  if (q) FUN_088050b8(q);
  DAT_08bf5e40 -= 1;
  struct G *g = DAT_08be8510;
  if (g) FUN_0882321c(&g->f, 2, -1);
  q = (int *)*p;
  if (q) FUN_088050b8(q);
}
// NEAR 6 words: global-address register allocation (retail t0 for counter lui, a3 for the pointer value; ours a3/v0). Tried local temps for both globals, typed struct pointer, int global, O2 (40 words, dup epilogue)
// near miss from lane lbp4b (unreviewed)
