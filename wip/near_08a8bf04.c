/* LBPMATCH module=EBOOT.BIN start=0x08a8bf04 end=0x08a8bf70 symbol=FUN_08a8bf04 lang=c99 */
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

extern int FUN_08a051ec();
extern void FUN_08a35ebc();

void FUN_08a8bf04(int param_1,int param_2,int param_3)
{
  int iVar1;
  uint local_20 [4];
  
  FUN_08a35ebc(param_1,param_2,param_3);
  local_20[0] = *(uint *)(param_1 + 0x318);
  iVar1 = FUN_08a051ec(param_2,local_20);
  if (param_2 + 4 == iVar1) {
    *(undefined4 *)(param_1 + 0x318) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x318) = *(undefined4 *)(iVar1 + 0x14);
  return;
}

// Primary profile initial candidate: 14 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
