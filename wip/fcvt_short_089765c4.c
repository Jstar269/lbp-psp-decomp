/* LBPMATCH module=EBOOT.BIN start=0x089765c4 end=0x08976600 symbol=FUN_089765c4 lang=c99 cc=gcc171-Os */
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

short FUN_089765c4(char *p)
{
  return (int)FUN_08b84224(*(float *)(*(int *)(p + 0x10) + 8) * (float)(int)*(short *)(p + 0x1c));
}
// 3 words off under cc=gcc171-Os (same as 0x0897641c): retail epilogue lw ra; addiu sp; mfc1 v0; jr; seh v0,v0 vs ours lw ra; mfc1 v1; seh v0,v1; jr; addiu sp.
// primary profile 16 off
// near miss from lane lbp4d (unreviewed)
