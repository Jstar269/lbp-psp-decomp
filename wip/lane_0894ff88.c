/* LBPMATCH module=EBOOT.BIN start=0x0894ff88 end=0x0895005c symbol=FUN_0894ff88 lang=c99 */
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
extern void FUN_08b899e4();

int FUN_0894ff88(int param_1,int param_2,int param_3,uint *param_4)
{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  if ((param_2 != 0) ||
     ((cVar4 = '\x01', param_3 != param_1 + 4 &&
      (cVar4 = '\0', *param_4 < *(uint *)(param_3 + 0x10))))) {
    cVar4 = '\x01';
  }
  piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0x18);
  if ((char *)piVar1 + 0x10 != (char *)0) {
    uVar3 = param_4[1];
    uVar2 = *param_4;
    piVar1[5] = uVar3;
    piVar1[4] = uVar2;
    if (uVar3 != 0) {
      *(int *)(uVar3 + 4) = *(int *)(uVar3 + 4) + 1;
    }
  }
  FUN_08b899e4(cVar4,piVar1,param_3,param_1 + 4);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return (int)piVar1;
}

// Generated starting point; primary compiler comparison remains unmatched.
// Allocation global load is hoisted; the shared-pointer member construction and null test also differ.
// near miss from lane lbp1c (unreviewed)
