/* LBPMATCH module=EBOOT.BIN start=0x0882e4c4 end=0x0882e560 symbol=FUN_0882e4c4 lang=c99 cc=gcc171-Os */
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

extern int FUN_0882db58();
extern int FUN_0882e25c();

int FUN_0882e4c4(int param_1,int *param_2)
{
  int iVar1;
  undefined4 local_18;
  int local_1c;
  int local_20;
  
  iVar1 = FUN_0882db58(param_1,param_2);
  if (((iVar1 == param_1 + 4) || (*param_2 < *(int *)(iVar1 + 0x10))) ||
     ((*param_2 <= *(int *)(iVar1 + 0x10) && (param_2[1] < *(int *)(iVar1 + 0x14))))) {
    local_1c = param_2[1];
    local_20 = *param_2;
    local_18 = 0;
    iVar1 = FUN_0882e25c(param_1,iVar1,&local_20);
  }
  return iVar1 + 0x18;
}

// best of the profile sweep: cc=gcc171-Os, 17 differing words left of 39.
// near miss from lane lbp2c (unreviewed)
