/* LBPMATCH module=EBOOT.BIN start=0x088d3174 end=0x088d31ac symbol=FUN_088d3174 lang=c99 cc=gcc410-Os rodata=0x08bb2218 */
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


float FUN_088d3174(int param_1)
{
  if (*(ushort *)(param_1 + 0x18) == 0) {
    return 100.0f;
  }
  return ((float)*(ushort *)(param_1 + 0x16) * 100.0f) / (float)*(ushort *)(param_1 + 0x18);
}
