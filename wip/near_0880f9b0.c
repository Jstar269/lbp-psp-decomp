/* LBPMATCH module=EBOOT.BIN start=0x0880f9b0 end=0x0880fa30 symbol=FUN_0880f9b0 lang=c99 */
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
extern undefined4 FUN_08adbb84();
extern void FUN_08b88fac();

void FUN_0880f9b0(int param_1,undefined4 *param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  
  *(int *)param_1 = param_1;
  puVar2 = (undefined4 *)*param_2;
  *(int *)(param_1 + 4) = param_1;
  for (; puVar2 != param_2; puVar2 = (undefined4 *)*puVar2) {
    piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0xc);
    if ((char *)piVar1 + 0x8 != (char *)0) {
      piVar1[2] = puVar2[2];
    }
    FUN_08b88fac(piVar1,param_1);
  }
  return;
}

// Primary profile initial candidate: 2 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
