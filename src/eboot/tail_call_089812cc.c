/* LBPMATCH module=EBOOT.BIN start=0x089812cc end=0x08981360 symbol=FUN_089812cc lang=c99 cc=gcc404xs-Os */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp2c, DeepSeek through Freebuff): the candidate carried cc=gcc171-Os (the lane primary gcc404xs-Os reproduces the whole prologue and the tail jump) and the translation dropped the call's sixth argument (retail li t1,2); exact match verified; names and types await human review. */
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

extern void FUN_089ce178();
extern void FUN_089db324(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6);

void FUN_089812cc(undefined4 param_1,undefined4 param_2,int param_3,int param_4)
{
  int *piVar1;
  
  piVar1 = (int *)(param_4 + 0x2cc);
  if (piVar1 != (int *)0x0) {
    FUN_089ce178(piVar1,param_3);
  }
  if ((undefined4 *)(param_4 + 0x280) != (undefined4 *)0x0) {
    FUN_089db324((undefined4 *)(param_4 + 0x280),piVar1,param_1,param_2,1,2);
    return;
  }
  return;
}
