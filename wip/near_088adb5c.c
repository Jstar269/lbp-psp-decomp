/* LBPMATCH module=EBOOT.BIN start=0x088adb5c end=0x088adb88 symbol=FUN_088adb5c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 2 word(s) differ; names and types await human review. */
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


void FUN_088adb5c(undefined4 *param_1)
{
  undefined4 *puVar1 = param_1 + 3;
  *puVar1 = puVar1[1] = (undefined4)puVar1;
  *param_1 = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  *(undefined2 *)((int)param_1 + 0x1e) = 0;
  return;
}
// differs: retail stores the sentinel's prev through the computed pointer first ('sw v0,4(v0)', then sh 30, then 'sw v0,12(a0)'); ours folds it to 16(a0) and puts it after the next store
// tried: ~30 store orders incl. chained assignment, separate prev/next statements
// near miss from lane lbp3a (unreviewed)
