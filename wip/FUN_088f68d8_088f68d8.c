/* LBPMATCH module=EBOOT.BIN start=0x088f68d8 end=0x088f6974 symbol=FUN_088f68d8 lang=c99 cc=gcc171-Os */
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

extern undefined * DAT_08beed14;
extern int FUN_088dc4b4();

undefined4 FUN_088f68d8(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((*(short *)(iVar1 + 6) == -1) && (*(short *)(iVar1 + 0x12) != -1)) {
    iVar2 = *(int *)(DAT_08beed14 + 0x150) + (uint)*(ushort *)(iVar1 + 0xe) * 0x28;
    iVar1 = FUN_088dc4b4(DAT_08beed14);
    if (*(int *)(iVar2 + 4) != 0) {
      return 1;
    }
    if (*(int *)(iVar2 + 8) != 0) {
      return 1;
    }
    if (*(int *)(iVar1 + 4) == 3) {
      return 1;
    }
    if (*(int *)(iVar1 + 4) == 4) {
      return 1;
    }
  }
  return 0;
}

// best of the profile sweep: cc=gcc171-Os, 19 differing words left of 39.
// near miss from lane lbp2c (unreviewed)
