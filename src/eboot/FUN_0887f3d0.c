/* LBPMATCH module=EBOOT.BIN start=0x0887f3d0 end=0x0887f414 symbol=FUN_0887f3d0 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review. */
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


bool FUN_0887f3d0(int param_1,int param_2,uchar param_3)
{
  if (param_3 != '\0') {
    return *(int *)(param_2 * 0x34 + param_1 + 0x598) != 0;
  }
  return *(int *)(param_2 * 0x30 + param_1 + 0x90) != 0;
}
