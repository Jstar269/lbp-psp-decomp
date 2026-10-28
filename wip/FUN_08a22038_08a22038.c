/* LBPMATCH module=EBOOT.BIN start=0x08a22038 end=0x08a22114 symbol=FUN_08a22038 lang=c99 cc=gcc171-Os */
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

extern int * DAT_08bf5df8;
extern int * DAT_08bf5e44;
extern void FUN_088050b8();
extern void FUN_08a20de8();
extern void FUN_08a61fa4();
extern void FUN_08a9e0cc();

void FUN_08a22038(void)
{
  int *piVar1;
  int *piVar2;
  
  piVar2 = DAT_08bf5e44;
  if (DAT_08bf5e44 != (int *)0x0) {
    if (DAT_08bf5e44[5] != 0) {
      FUN_08a61fa4(DAT_08bf5e44[5],*DAT_08bf5e44);
      piVar2[5] = 0;
    }
    piVar1 = DAT_08bf5df8;
    if (DAT_08bf5df8 != (int *)0x0) {
      FUN_08a20de8(DAT_08bf5df8);
      FUN_08a9e0cc((uint)piVar1);
    }
    DAT_08bf5df8 = (int *)*piVar2;
    *piVar2 = 0;
    if (piVar2[5] != 0) {
      FUN_08a61fa4(piVar2[5],0);
      piVar2[5] = 0;
    }
    piVar1 = DAT_08bf5df8;
    if (DAT_08bf5df8 != (int *)0x0) {
      FUN_08a20de8(DAT_08bf5df8);
      FUN_08a9e0cc((uint)piVar1);
    }
    DAT_08bf5df8 = (int *)*piVar2;
    *piVar2 = 0;
    if ((int *)piVar2[0x19] != (int *)0x0) {
      FUN_088050b8((int *)piVar2[0x19]);
    }
    FUN_08a9e0cc((uint)piVar2);
  }
  DAT_08bf5e44 = (int *)0x0;
  return;
}

// residual: two independent stores per block are emitted in the opposite order (`sw v0,DAT;s2` then `sw zero,0(s1)` in retail);
// the swapped source order makes the whole loop 34 words differ, the given order leaves exactly these two pairs. parked.
// near miss from lane lbp2b (unreviewed)
