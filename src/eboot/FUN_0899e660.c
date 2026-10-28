/* LBPMATCH module=EBOOT.BIN start=0x0899e660 end=0x0899e684 symbol=FUN_0899e660 lang=c99 cc=gcc410-Os rodata=0x08bab59c */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review. */
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


float FUN_0899e660(float param_1)
{
  float fVar1;
  
  fVar1 = (1.0f - (param_1 - 1.0f) * (param_1 - 1.0f)) - 1.0f;
  return 1.0f - fVar1 * fVar1;
}
