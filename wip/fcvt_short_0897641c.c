/* LBPMATCH module=EBOOT.BIN start=0x0897641c end=0x08976458 symbol=FUN_0897641c lang=c99 cc=gcc171-Os */
/* Hand-written reconstruction from the disassembly (lane lbp4d, Claude Sonnet 5.5); NEAR MISS, not exact. */
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

extern float FUN_08b84224(float param_1);

short FUN_0897641c(char *p)
{
  return (int)FUN_08b84224(*(float *)(*(int *)(p + 0x10) + 8) * (float)(int)*(short *)(p + 0x1e));
}
// 3 words off under cc=gcc171-Os (primary: 16 off): retail epilogue lw ra; addiu sp; mfc1 v0; jr; seh v0,v0 vs ours lw ra; mfc1 v1; seh v0,v1; jr; addiu sp.
// tried return types short/int, local short, O2/O1, 4.0.x profiles
// near miss from lane lbp4d (unreviewed)
