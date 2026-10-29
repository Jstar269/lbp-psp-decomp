/* LBPMATCH module=EBOOT.BIN start=0x08a51ca4 end=0x08a51d20 symbol=FUN_08a51ca4 lang=c99 */
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

extern int FUN_0880f178();

void FUN_08a51ca4(char *param_1,char *param_2)
{
  int *piVar1;
  int iVar2;
  char *iVar3;
  uint local_1c [3];
  uint local_20;
  
  iVar3 = param_1 + 0x18;
  iVar2 = param_1;
  if (*(unsigned char *)(param_1 + 0x5a0) != '\0') {
    iVar2 = param_1 + 0x5a4;
    iVar3 = param_1 + 0x5bc;
  }
  local_1c[0] = *(uint *)(param_2 + 4);
  piVar1 = (int *)FUN_0880f178(iVar2,local_1c);
  iVar2 = *(int *)(param_2 + 0x44);
  local_20 = *(uint *)(param_2 + 4);
  *piVar1 = param_2;
  piVar1 = (int *)FUN_0880f178(iVar3 + iVar2 * 0x18,&local_20);
  *piVar1 = param_2;
  return;
}

// 6 words differ: pointer base and store scheduling; unsigned flag corrects byte load.
// near miss from lane lbp5a (unreviewed)
