/* LBPMATCH module=EBOOT.BIN start=0x08b8f24c end=0x08b8f288 symbol=FUN_08b8f24c lang=c99 */
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


int FUN_08b8f24c(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar2 = 0;
  if (iVar1 < *(int *)(param_1 + 0x18)) {
    *(int *)(param_1 + 0x14) = iVar1 + 1;
    iVar2 = *(int *)(param_1 + 0x10) + iVar1 * 0xc;
  }
  return iVar2;
}

// 3 words off: retail forms 12*i as (i<<4) in v0, (i<<2) in a0, subu a0,v0,a0; ours (i<<2) v0, (i<<4) a0, subu a0,a0,v0 (shift order only).
// tried struct-array index, p->e + i, char* arithmetic, operand orders; gcc402t-Os has the same 3 diffs, 171/410 worse
// near miss from lane lbp4d (unreviewed)
