/* LBPMATCH module=EBOOT.BIN start=0x08a1c078 end=0x08a1c378 symbol=FUN_08a1c078 lang=c99 */
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


void FUN_08a1c078(undefined4 *param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_2 + 4) == 0) {
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    iVar2 = 0;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c0b0;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c278:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c0e4;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c298:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c118;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c2b8:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c14c;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c2d8:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c180;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c2f8:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c1b4;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c318:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (uVar3 <= *(uint *)(param_2 + 0xc)) goto LAB_08a1c1e8;
    *(uint *)(param_2 + 0xc) = uVar3;
LAB_08a1c338:
    iVar2 = 0;
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (*(uint *)(param_2 + 0xc) < uVar3) {
      *(uint *)(param_2 + 0xc) = uVar3;
      bVar1 = true;
      goto joined_r0x08a1c350;
    }
  }
  else {
    **(undefined4 **)(param_2 + 8) = *param_1;
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c0b0:
    if (iVar2 == 0) goto LAB_08a1c278;
    **(undefined4 **)(param_2 + 8) = param_1[1];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c0e4:
    if (iVar2 == 0) goto LAB_08a1c298;
    **(undefined4 **)(param_2 + 8) = param_1[2];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c118:
    if (iVar2 == 0) goto LAB_08a1c2b8;
    **(undefined4 **)(param_2 + 8) = param_1[3];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c14c:
    if (iVar2 == 0) goto LAB_08a1c2d8;
    **(undefined4 **)(param_2 + 8) = param_1[4];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c180:
    if (iVar2 == 0) goto LAB_08a1c2f8;
    **(undefined4 **)(param_2 + 8) = param_1[5];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c1b4:
    if (iVar2 == 0) goto LAB_08a1c318;
    **(undefined4 **)(param_2 + 8) = param_1[6];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
LAB_08a1c1e8:
    if (iVar2 == 0) goto LAB_08a1c338;
    **(undefined4 **)(param_2 + 8) = param_1[7];
    iVar2 = *(int *)(param_2 + 4);
    uVar3 = *(int *)(param_2 + 0x10) + 4;
    *(uint *)(param_2 + 8) = iVar2 + uVar3;
    *(uint *)(param_2 + 0x10) = uVar3;
  }
  bVar1 = iVar2 == 0;
joined_r0x08a1c350:
  if (bVar1) {
    uVar3 = uVar3 + 4;
    *(uint *)(param_2 + 0x10) = uVar3;
    if (*(uint *)(param_2 + 0xc) < uVar3) {
      *(uint *)(param_2 + 0xc) = uVar3;
    }
    return;
  }
  **(undefined4 **)(param_2 + 8) = param_1[8];
  iVar2 = *(int *)(param_2 + 0x10) + 4;
  *(int *)(param_2 + 8) = *(int *)(param_2 + 4) + iVar2;
  *(int *)(param_2 + 0x10) = iVar2;
  return;
}

// Generated candidate needs unaligned-access and control-flow reconstruction.
// near miss from lane lbp15d (unreviewed)
