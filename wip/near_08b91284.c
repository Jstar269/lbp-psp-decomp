/* LBPMATCH module=EBOOT.BIN start=0x08b91284 end=0x08b912fc symbol=FUN_08b91284 lang=c99 */
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

extern void FUN_08b911f4();

void FUN_08b91284(char *param_1,undefined1 param_2)
{
  uint uVar1;
  char *iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    uVar1 = *(uint *)(param_1 + 8);
    if (*(uint *)(param_1 + 0xc) <= uVar1) {
      FUN_08b911f4(param_1,1);
      iVar2 = *(int *)(param_1 + 4);
      if (iVar2 == 0) {
        return;
      }
      uVar1 = *(uint *)(param_1 + 8);
    }
    *(undefined1 *)(iVar2 + uVar1) = param_2;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return;
}

// Primary profile initial candidate: 20 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
