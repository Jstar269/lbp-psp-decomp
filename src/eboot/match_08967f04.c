/* LBPMATCH module=EBOOT.BIN start=0x08967f04 end=0x08967fb4 symbol=FUN_08967f04 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1b, Codex GPT-6): corrected byte signedness; exact match verified; names and types await human review. */
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

extern void FUN_088cc71c();
extern void FUN_08967e24();
extern void FUN_0897633c();
extern void FUN_089d1dfc();

void FUN_08967f04(int param_1,short *param_2,short *param_3,undefined4 param_4)
{
  int iVar1;
  undefined4 auStack_40 [2];
  int aiStack_38 [2];
  undefined4 auStack_30 [2];
  int aiStack_28 [2];
  
  iVar1 = *(int *)(param_1 + 0x44);
  FUN_0897633c(auStack_30,param_2);
  FUN_089d1dfc(iVar1,auStack_30,'\0');
  FUN_088cc71c(aiStack_28);
  iVar1 = *(int *)(param_1 + 0x4c);
  FUN_0897633c(auStack_40,param_3);
  FUN_089d1dfc(iVar1,auStack_40,'\0');
  FUN_088cc71c(aiStack_38);
  *(undefined4 *)(param_1 + 0x3c) = param_4;
  if (*(unsigned char *)(param_1 + 0x58) == '\0') {
    FUN_08967e24(param_1);
  }
  return;
}

