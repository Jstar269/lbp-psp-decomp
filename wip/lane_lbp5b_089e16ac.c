/* LBPMATCH module=EBOOT.BIN start=0x089e16ac end=0x089e174c symbol=FUN_089e16ac lang=c99 */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08a1b424();
extern void FUN_08a9e0cc();
extern undefined4 FUN_08adbb84();
extern void FUN_08b88fac();

void FUN_089e16ac(int *param_1,int *param_2,int param_3)
{
  int *piVar1;
  uint *puVar2;
  
  puVar2 = (uint *)*param_2;
  if (puVar2 != (uint *)0x0) {
    if ((uint)(*param_1 - param_3) < 2) {
      piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0xc);
      if ((char *)piVar1 + 0x8 != (char *)0) {
        piVar1[2] = *param_2;
      }
      FUN_08b88fac(piVar1,(int)(param_1 + 1));
      *param_2 = 0;
    }
    else {
      FUN_08a1b424(puVar2);
      FUN_08a9e0cc((uint)puVar2);
      *param_2 = 0;
    }
  }
  return;
}

// NEAR: 12 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
