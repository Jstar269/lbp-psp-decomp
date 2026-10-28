/* LBPMATCH module=EBOOT.BIN start=0x088231d8 end=0x0882321c symbol=FUN_088231d8 lang=c99 cc=gcc171-Os rodata=0x08bac174 */
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

extern undefined * DAT_08be84a4;

float FUN_088231d8(void)
{
  return (float)*(uint *)(DAT_08be84a4 + 0x281c) / 2560.0f;
}
