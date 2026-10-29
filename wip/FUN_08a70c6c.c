/* LBPMATCH module=EBOOT.BIN start=0x08a70c6c end=0x08a70d0c symbol=FUN_08a70c6c lang=c99 */
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

extern undefined * FUN_0891a58c();
extern undefined4 FUN_0891b124();

void FUN_08a70c6c(int param_1,int param_2,int param_3,undefined1 param_4)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_2 + 0x98);
  iVar3 = *(int *)(param_3 + 0x98);
  (**(code **)(*piVar2 + 0xf8))
            (piVar2,iVar3,param_1,*(int *)(param_2 + 0x40) == *(int *)(param_1 + 4),param_4);
  puVar1 = (undefined4 *)FUN_0891a58c();
  FUN_0891b124(puVar1,param_1,param_2,param_3,(int)piVar2,iVar3);
  return;
}

// 9 words differ: indirect virtual call register allocation; likely requires C++ member declaration.
// near miss from lane lbp5a (unreviewed)
