/* LBPMATCH module=EBOOT.BIN start=0x08a34c8c end=0x08a34d24 symbol=FUN_08a34c8c lang=c99 cc=gcc402x-O2 */
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

extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a52bb8();

undefined4 FUN_08a34c8c(int param_1,int *param_2,char param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x90) != -1) {
    if (*(int *)(param_1 + 0x90) == *param_2) {
      return 1;
    }
    if (param_3 != '\0') {
      iVar1 = FUN_08a50fbc();
      iVar1 = FUN_08a52bb8(iVar1,(uint *)(param_1 + 0x90));
      uVar2 = FUN_08a34c8c(iVar1,param_2,'\x01');
      return uVar2;
    }
  }
  return 0;
}

// profile sweep: 20 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
