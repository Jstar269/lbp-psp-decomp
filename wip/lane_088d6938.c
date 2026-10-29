/* LBPMATCH module=EBOOT.BIN start=0x088d6938 end=0x088d6a10 symbol=FUN_088d6938 lang=c99 */
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

extern undefined2 DAT_08beecb2;
extern void FUN_088d5f9c();

void FUN_088d6938(uint *param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x7c0) == 0) {
    FUN_088d5f9c(param_1,'\x01',0x40);
    uVar1 = *param_1;
    goto LAB_088d69b0;
  }
  if ((uVar1 & 0x80) == 0) {
    if ((uVar1 & 0x100) == 0) {
      uVar1 = *param_1;
      goto LAB_088d69b0;
    }
    uVar2 = uVar1 & 0xfffffebf;
    *param_1 = uVar2;
    if ((uVar1 & 0x80000) != 0) goto LAB_088d699c;
    uVar2 = uVar2 | 0x40;
  }
  else {
    uVar2 = uVar1 & 0xffffff3f;
LAB_088d699c:
    uVar2 = uVar2 | 0x200;
  }
  *param_1 = uVar2;
  uVar1 = *param_1;
LAB_088d69b0:
  uVar2 = param_1[10];
  *param_1 = uVar1 & 0xffe7ffdf;
  if (((uVar2 == 3) || (uVar2 == 5)) || (uVar2 == 4)) {
    DAT_08beecb2 = 1;
  }
  else if (uVar2 != 2) {
    *param_1 = uVar1 & 0xffe7ffdf | 0x8000;
  }
  return;
}

// Initial primary-profile candidate: 43 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
