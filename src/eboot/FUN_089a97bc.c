/* LBPMATCH module=EBOOT.BIN start=0x089a97bc end=0x089a9800 symbol=FUN_089a97bc lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review. */
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

extern undefined4 FUN_089a5fbc();

undefined4 FUN_089a97bc(int *param_1)
{
  int iVar1;
  
  if ((param_1 != (int *)0x0) &&
     (iVar1 = FUN_089a5fbc(2,param_1,(uint *)0x0,(int *)0x0), iVar1 != 0)) {
    return 1;
  }
  return 0;
}
