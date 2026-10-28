/* LBPMATCH module=EBOOT.BIN start=0x08970494 end=0x08970540 symbol=FUN_08970494 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1c, Codex GPT-6): return type and third call argument; matching idiom: stack local passed to callee which does not inspect it; exact match verified; names and types await human review. */
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
typedef float undefined4;

extern undefined4 * FUN_0896b4a0();
extern void FUN_08970b6c();
extern void FUN_08978c04();
extern int FUN_08978ef0();

void FUN_08970494(int param_1,int param_2,int param_3)
{
  int iVar1;
  int temp;
  undefined4 *local_18 [2];
  undefined4 *local_1c;
  
  FUN_0896b4a0(local_18,0,&temp);
  iVar1 = FUN_08978ef0(*(int *)(param_2 * 4 + param_1 + 0x2c),param_3);
  local_1c = local_18[0];
  if (local_18[0] != (undefined4 *)0x0) {
    *(short *)((int)local_18[0] + 6) = *(short *)((int)local_18[0] + 6) + 1;
  }
  FUN_08978c04(iVar1,(int *)&local_1c);
  if (local_1c != (undefined4 *)0x0) {
    FUN_08970b6c(local_1c);
  }
  if (local_18[0] != (undefined4 *)0x0) {
    FUN_08970b6c(local_18[0]);
  }
  return;
}



