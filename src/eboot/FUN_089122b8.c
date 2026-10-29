/* LBPMATCH module=EBOOT.BIN start=0x089122b8 end=0x08912304 symbol=FUN_089122b8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): swapped the last two stores; exact match verified; names and types await human review. */
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

extern void FUN_08a9bff8();
extern undefined4 * FUN_08a9d390();

void FUN_089122b8(undefined1 *param_1)
{
  undefined4 auStack_30 [8];
  
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_08a9d390(auStack_30,0xffffffff);
  FUN_08a9bff8((int)auStack_30);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}
