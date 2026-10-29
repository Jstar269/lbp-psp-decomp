/* LBPMATCH module=EBOOT.BIN start=0x0882db58 end=0x0882dbb4 symbol=FUN_0882db58 lang=c99 cc=gcc404xs-O2 */
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


int FUN_0882db58(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 + 4;
  iVar2 = *(int *)(param_1 + 8);
LAB_0882db9c:
  do {
    if (iVar2 == 0) {
      return iVar1;
    }
    if (*param_2 <= *(int *)(iVar2 + 0x10)) {
      if (*param_2 < *(int *)(iVar2 + 0x10)) {
        iVar1 = iVar2;
        iVar2 = *(int *)(iVar2 + 8);
        goto LAB_0882db9c;
      }
      if (param_2[1] <= *(int *)(iVar2 + 0x14)) {
        iVar1 = iVar2;
        iVar2 = *(int *)(iVar2 + 8);
        goto LAB_0882db9c;
      }
    }
    iVar2 = *(int *)(iVar2 + 0xc);
  } while( true );
}


// 18 words differ in tree walk layout; primary Os and O2 tested.
// near miss from lane lbp14b (unreviewed)
