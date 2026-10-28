/* LBPMATCH module=EBOOT.BIN start=0x08aa3c68 end=0x08aa3d54 symbol=FUN_08aa3c68 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1c, Codex GPT-6): reconstructed loop condition; exact match verified; names and types await human review. */
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

extern void FUN_08a9df6c();
extern int FUN_08a9e4a4();

void FUN_08aa3c68(int *param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int *param_6, undefined4 param_7,int param_8)
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = FUN_08a9e4a4(param_4 << 2,0,0);
  while (uVar2 < param_5) {
    (**(code **)(*param_1 + 0x24))(param_1,uVar1,param_2,uVar2 + param_3,param_4);
    (**(code **)(*param_6 + 0x28))(param_6,uVar1,param_7,uVar2 + param_8,param_4);
    uVar2 = uVar2 + 1;
  }
  FUN_08a9df6c(uVar1);
  return;
}

