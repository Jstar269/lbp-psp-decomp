/* LBPMATCH module=EBOOT.BIN start=0x088e1dc4 end=0x088e1e70 symbol=FUN_088e1dc4 lang=c99 rodata=0x08bb4760 */
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


bool FUN_088e1dc4(undefined4 *param_1,uint *param_2,uint *param_3)
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  
  switch(*param_1) {
  case 0:
    uVar3 = param_2[0x1c];
    uVar2 = param_3[0x1c];
    break;
  case 1:
  case 0xb:
    uVar3 = (uint)*(byte *)((int)param_2 + 0x8e);
    uVar2 = (uint)*(byte *)((int)param_3 + 0x8e);
    break;
  case 2:
    uVar3 = param_2[3];
    uVar2 = param_3[3];
    break;
  default:
    return false;
  case 0xc:
    uVar1 = (ushort)param_2[0x20];
    uVar4 = uVar1;
    if (((*param_2 & 0x10) != 0) && (uVar4 = 1, 1 < uVar1)) {
      uVar4 = uVar1;
    }
    uVar1 = (ushort)param_3[0x20];
    uVar5 = uVar1;
    if (((*param_3 & 0x10) != 0) && (uVar5 = 1, 1 < uVar1)) {
      uVar5 = uVar1;
    }
    return uVar5 < uVar4;
  }
  return uVar2 < uVar3;
}

// Initial primary-profile candidate: 28 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
