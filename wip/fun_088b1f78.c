/* LBPMATCH module=EBOOT.BIN start=0x088b1f78 end=0x088b2010 symbol=FUN_088b1f78 lang=c99 */
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

extern void FUN_08921170();
extern void FUN_089eac94();

void FUN_088b1f78(int *param_1,int param_2)
{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *apuStack_30 [4];
  
  iVar1 = *param_1;
  puVar2 = *(uint **)(iVar1 + 0x2c);
  apuStack_30[0] = puVar2;
  if (*(int *)(iVar1 + 0x34) == 0) {
    puVar3 = (uint *)((int)puVar2 + *(int *)(iVar1 + 0x28));
    for (; puVar2 < puVar3; puVar2 = puVar2 + 1) {
      FUN_089eac94(*puVar2);
    }
  }
  if (apuStack_30[0] != (uint *)0x0) {
    FUN_08921170(param_1,(int *)apuStack_30);
  }
  *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + -1;
  return;
}

// Baseline generated candidate; 26 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// Revisit: retail passes a third zero argument to FUN_08921170; correcting it yields 27 positional differences, with a missing move before the loop. Typed structures did not fix allocation; O2 was worse.
// near miss from lane lbp8f (unreviewed)
