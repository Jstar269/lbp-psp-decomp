/* LBPMATCH module=EBOOT.BIN start=0x0894c154 end=0x0894c30c symbol=FUN_0894c154 lang=c99 */
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

extern char DAT_08bef988;
extern void FUN_0883bfbc();
extern void FUN_089218b4();
extern void FUN_0894b790();
extern void FUN_0894b890();
extern void FUN_0894c0c4();

void FUN_0894c154(int *param_1,int param_2,int param_3)
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint local_20;
  
  FUN_0883bfbc(&DAT_08bef988);
  FUN_0894b790((int)param_1,param_2,param_3);
  if (param_1[1] == 0) goto LAB_0894c2cc;
  while( true ) {
    local_20 = *(uint *)(param_2 + 0x10);
    uVar3 = local_20 + 1;
    if ((local_20 & 3) == 0) break;
    if (*(int *)(param_2 + 4) == 0) {
      *(uint *)(param_2 + 0x10) = uVar3;
      if (*(uint *)(param_2 + 0xc) < uVar3) {
        *(uint *)(param_2 + 0xc) = uVar3;
      }
    }
    else {
      **(undefined1 **)(param_2 + 8) = 0;
      iVar2 = *(int *)(param_2 + 0x10) + 1;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 4) + iVar2;
      *(int *)(param_2 + 0x10) = iVar2;
    }
  }
  FUN_0894b890(param_1,param_2,param_3,param_1[2]);
  if (param_1[2] == 1) {
    local_20 = local_20 - *(int *)(param_2 + 0x10);
  }
  if (param_3 == 1) {
    local_20 = local_20 << 0x18 | (local_20 & 0xff00) << 8 | local_20 >> 8 & 0xff00 |
               local_20 >> 0x18;
    if (*(int *)(param_2 + 4) != 0) {
      puVar1 = *(uint **)(param_2 + 8);
LAB_0894c288:
      __builtin_memcpy(puVar1, &local_20, 4);
      iVar2 = *(int *)(param_2 + 0x10) + 4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 4) + iVar2;
      *(int *)(param_2 + 0x10) = iVar2;
      goto LAB_0894c2cc;
    }
  }
  else if (*(int *)(param_2 + 4) != 0) {
    puVar1 = *(uint **)(param_2 + 8);
    goto LAB_0894c288;
  }
  uVar3 = *(int *)(param_2 + 0x10) + 4;
  *(uint *)(param_2 + 0x10) = uVar3;
  if (*(uint *)(param_2 + 0xc) < uVar3) {
    *(uint *)(param_2 + 0xc) = uVar3;
  }
LAB_0894c2cc:
  FUN_0894c0c4((int)param_1,param_2,param_3);
  FUN_089218b4(param_2,0,2);
  FUN_0883bfbc(&DAT_08bef988);
  return;
}

// Generated g14 candidate; symbolic address and unaligned store corrected; control flow needs refinement.
// near miss from lane lbp13c (unreviewed)
