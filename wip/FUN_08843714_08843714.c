/* LBPMATCH module=EBOOT.BIN start=0x08843714 end=0x088437b8 symbol=FUN_08843714 lang=c99 cc=gcc404xs-Os */
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


void FUN_08843714(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  if (iVar1 == param_1 + 0x2c) {
    iVar1 = 0;
  }
  iVar1 = (**(code **)(*param_2 + 0x10))(param_2,param_1,iVar1);
  if (iVar1 == 0) {
    iVar1 = *param_2;
  }
  else {
    for (piVar2 = *(int **)(param_1 + 0x18); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[10]) {
      iVar1 = (**(code **)(*piVar2 + 0x44))(piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = *param_2;
        goto LAB_08843790;
      }
    }
    iVar1 = *param_2;
  }
LAB_08843790:
  (**(code **)(iVar1 + 0x14))(param_2,param_1);
  return;
}

// best of the profile sweep: cc=gcc404xs-Os, 19 differing words left of 41.
// near miss from lane lbp2c (unreviewed)
