/* LBPMATCH module=EBOOT.BIN start=0x089e8ee0 end=0x089e8f70 symbol=FUN_089e8ee0 lang=c99 */
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
extern void FUN_0896dddc();
extern void FUN_08adbc24();

void FUN_089e8ee0(undefined4 *param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = param_1 + 0x1a;
  for (puVar2 = (undefined4 *)param_1[0x1a]; puVar2 != puVar4; puVar2 = (undefined4 *)*puVar2) {
    piVar1 = (int *)puVar2[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  puVar2 = (undefined4 *)*puVar4;
  while (puVar2 != puVar4) {
    puVar3 = (undefined4 *)*puVar2;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar2,0xc);
    puVar2 = puVar3;
  }
  param_1[0x1b] = puVar4;
  *puVar4 = puVar4;
  FUN_0896dddc(param_1);
  return;
}

// Primary profile initial candidate: 1 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
