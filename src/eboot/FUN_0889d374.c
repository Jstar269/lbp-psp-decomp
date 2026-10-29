/* LBPMATCH module=EBOOT.BIN start=0x0889d374 end=0x0889d3a4 symbol=FUN_0889d374 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): swapped the loop increments so the source pointer advances before the destination (placement-new copy loop); exact match verified; names and types await human review. */
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


undefined4 * FUN_0889d374(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)
{
  for (; param_1 != param_2; param_1 = param_1 + 1, param_3 = param_3 + 1) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
    }
  }
  return param_3;
}
