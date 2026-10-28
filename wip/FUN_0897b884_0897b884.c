/* LBPMATCH module=EBOOT.BIN start=0x0897b884 end=0x0897b968 symbol=FUN_0897b884 lang=c99 cc=gcc402x-O1 */
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

extern undefined4 DAT_08bf03b8;
extern void FUN_0896f07c();
extern void FUN_0897a4a4();

void FUN_0897b884(int param_1)
{
  FUN_0897a4a4(param_1 + 0x4c);
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0896f07c(DAT_08bf03b8,1,*(int *)(param_1 + 8));
    if (*(int **)(param_1 + 8) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 8) + 4))();
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_0896f07c(DAT_08bf03b8,1,*(int *)(param_1 + 0x20));
    if (*(int **)(param_1 + 0x20) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x20) + 4))();
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_0896f07c(DAT_08bf03b8,1,*(int *)(param_1 + 0x38));
    if (*(int **)(param_1 + 0x38) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x38) + 4))();
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return;
}

// profile sweep: 30 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
