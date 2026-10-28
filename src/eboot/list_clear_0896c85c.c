/* LBPMATCH module=EBOOT.BIN start=0x0896c85c end=0x0896c8dc symbol=FUN_0896c85c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2b, DeepSeek through Freebuff): the two list-head stores are written +4 before +0, which is the order retail emits; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08adbc24();

void FUN_0896c85c(undefined4 *param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  for (puVar2 = (undefined4 *)*param_1; puVar2 != param_1; puVar2 = (undefined4 *)*puVar2) {
    piVar1 = (int *)puVar2[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  puVar2 = (undefined4 *)*param_1;
  while (puVar2 != param_1) {
    puVar3 = (undefined4 *)*puVar2;
    FUN_08adbc24(DAT_08be84a0,(uint)puVar2,0xc);
    puVar2 = puVar3;
  }
  *param_1 = param_1;
  param_1[1] = param_1;
  return;
}
