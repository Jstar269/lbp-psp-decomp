/* LBPMATCH module=EBOOT.BIN start=0x08889224 end=0x08889250 symbol=FUN_08889224 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): string length over unsigned short elements (retail lhu); exact match verified; names and types await human review. */
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


int FUN_08889224(unsigned short *param_1)
{
  unsigned short *psVar1;
  
  psVar1 = param_1;
  if (param_1 == (unsigned short *)0x0) {
    return 0;
  }
  for (; *psVar1 != 0; psVar1 = psVar1 + 1) {
  }
  return (int)psVar1 - (int)param_1 >> 1;
}
