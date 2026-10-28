/* LBPMATCH module=EBOOT.BIN start=0x08a7125c end=0x08a712f4 symbol=FUN_08a7125c lang=c99 cc=gcc402x-O2 */
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

extern int * FUN_08a05040();

int * FUN_08a7125c(int *param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  do {
    piVar3 = param_1;
    iVar1 = (**(code **)(*piVar3 + 0x5c))(piVar3);
    piVar2 = FUN_08a05040(iVar1);
    if (piVar2 != (int *)0x0) {
      return piVar2;
    }
    param_1 = (int *)piVar3[0x26];
  } while ((int *)piVar3[0x26] != (int *)0x0);
  piVar4 = (int *)piVar3[0x27];
  piVar2 = (int *)0x0;
  if (piVar4 != piVar3 + 0x27) {
    piVar2 = (int *)piVar4[2];
    while( true ) {
      iVar1 = (**(code **)(*piVar2 + 0x5c))();
      piVar2 = FUN_08a05040(iVar1);
      if (piVar2 != (int *)0x0) break;
      piVar4 = (int *)*piVar4;
      if (piVar4 == piVar3 + 0x27) {
        return (int *)0x0;
      }
      piVar2 = (int *)piVar4[2];
    }
  }
  return piVar2;
}

// profile sweep: 20 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
