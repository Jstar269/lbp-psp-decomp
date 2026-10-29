/* LBPMATCH module=EBOOT.BIN start=0x08a3fe70 end=0x08a3fee8 symbol=FUN_08a3fe70 lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3b, Claude Sonnet 5.5): gcc404xs-O2 header; first argument of FUN_08a3fce4 is float 0.0; exact match verified; names and types await human review. */
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

extern void FUN_08a0a254();
extern void FUN_08a0d540();
extern void FUN_08a3fce4(float, int, int);

void FUN_08a3fe70(int param_1)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 400);
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2);
    FUN_08a0a254(*(int *)(param_1 + 400));
    FUN_08a3fce4(0.0f,param_1,1);
    FUN_08a0d540(iVar1);
    return;
  }
  return;
}
