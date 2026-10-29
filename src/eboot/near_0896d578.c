/* LBPMATCH module=EBOOT.BIN start=0x0896d578 end=0x0896d63c symbol=FUN_0896d578 lang=c99 rodata=0x08bb89f8 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp3a, Claude Sonnet 5.5): callees declared as returning short (0x0896c61c ends with seh v0): this keeps GCC from turning the calls into tail calls as retail did not; parameters 6 and 7 are int; unused short locals dropped; exact match verified; names and types await human review. */
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

extern short FUN_0896c4bc();
extern short FUN_0896c61c();
extern short FUN_0896ced8();
extern short FUN_0896d028();
extern short FUN_0896d180();
extern short FUN_0896d2b8();
extern short FUN_0896d410();

int FUN_0896d578(int param_1,undefined4 param_2,int *param_3,int param_4,int param_5,int param_6, int param_7)
{
  int iVar1;
  
  iVar1 = 0;
  switch(param_2) {
  case 0:
    iVar1 = FUN_0896c61c(param_1,param_3,param_4,param_5);
    break;
  case 1:
    iVar1 = FUN_0896d410(param_1,param_3,param_4,param_5,param_7);
    break;
  case 2:
    iVar1 = FUN_0896d2b8(param_1,param_3,param_4,param_5);
    break;
  case 3:
    iVar1 = FUN_0896d180(param_1,param_3,param_4,param_5,param_6 + param_7);
    break;
  case 4:
    iVar1 = FUN_0896d028(param_1,param_3,param_4,param_5,param_6 + param_7);
    break;
  case 5:
    iVar1 = FUN_0896ced8(param_1,param_3,param_4,param_5,param_6,param_7);
    break;
  case 6:
    iVar1 = FUN_0896c4bc(param_1,param_3,param_4,param_5,param_6,param_7);
  }
  return iVar1;
}
