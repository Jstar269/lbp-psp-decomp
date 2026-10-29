/* LBPMATCH module=EBOOT.BIN start=0x0891700c end=0x08917054 symbol=FUN_0891700c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3c, Claude Sonnet 5.5): swapped the two independent stores to retail's emitted order; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08bef4b0;
extern undefined * DAT_08bef4b4;
extern void FUN_08916e64();

void FUN_0891700c(int param_1)
{
  undefined4 *puVar1;
  
  FUN_08916e64(DAT_08bef4b0,param_1);
  puVar1 = (undefined4 *)(DAT_08bef4b4 + param_1 * 0x10);
  *puVar1 = 0;
  puVar1[3] = 0;
  return;
}
