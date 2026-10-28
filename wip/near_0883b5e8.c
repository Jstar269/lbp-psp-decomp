/* LBPMATCH module=EBOOT.BIN start=0x0883b5e8 end=0x0883b8fc symbol=FUN_0883b5e8 lang=c99 */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08adbc24();

void FUN_0883b5e8(undefined4 param_1,int param_2)
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_3c;
  undefined4 local_34;
  
  local_34 = param_2;
  while (local_34 != 0) {
    local_3c = *(uint *)(local_34 + 0xc);
    while (local_3c != 0) {
      uVar9 = *(uint *)(local_3c + 0xc);
      while (uVar9 != 0) {
        uVar8 = *(uint *)(uVar9 + 0xc);
        while (uVar8 != 0) {
          uVar7 = *(uint *)(uVar8 + 0xc);
          while (uVar7 != 0) {
            uVar6 = *(uint *)(uVar7 + 0xc);
            while (uVar6 != 0) {
              uVar5 = *(uint *)(uVar6 + 0xc);
              while (uVar5 != 0) {
                uVar4 = *(uint *)(uVar5 + 0xc);
                while (uVar4 != 0) {
                  uVar10 = *(uint *)(uVar4 + 0xc);
                  while (uVar10 != 0) {
                    FUN_0883b5e8(param_1,*(int *)(uVar10 + 0xc));
                    uVar1 = *(uint *)(uVar10 + 8);
                    puVar3 = *(undefined4 **)(uVar10 + 0x14);
                    while (puVar3 != (undefined4 *)(uVar10 + 0x14)) {
                      puVar2 = (undefined4 *)*puVar3;
                      FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
                      puVar3 = puVar2;
                    }
                    FUN_08adbc24(DAT_08be84a0,uVar10,0x1c);
                    uVar10 = uVar1;
                  }
                  uVar10 = *(uint *)(uVar4 + 8);
                  puVar3 = *(undefined4 **)(uVar4 + 0x14);
                  while (puVar3 != (undefined4 *)(uVar4 + 0x14)) {
                    puVar2 = (undefined4 *)*puVar3;
                    FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
                    puVar3 = puVar2;
                  }
                  FUN_08adbc24(DAT_08be84a0,uVar4,0x1c);
                  uVar4 = uVar10;
                }
                uVar4 = *(uint *)(uVar5 + 8);
                puVar3 = *(undefined4 **)(uVar5 + 0x14);
                while (puVar3 != (undefined4 *)(uVar5 + 0x14)) {
                  puVar2 = (undefined4 *)*puVar3;
                  FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
                  puVar3 = puVar2;
                }
                FUN_08adbc24(DAT_08be84a0,uVar5,0x1c);
                uVar5 = uVar4;
              }
              uVar5 = *(uint *)(uVar6 + 8);
              puVar3 = *(undefined4 **)(uVar6 + 0x14);
              while (puVar3 != (undefined4 *)(uVar6 + 0x14)) {
                puVar2 = (undefined4 *)*puVar3;
                FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
                puVar3 = puVar2;
              }
              FUN_08adbc24(DAT_08be84a0,uVar6,0x1c);
              uVar6 = uVar5;
            }
            uVar6 = *(uint *)(uVar7 + 8);
            puVar3 = *(undefined4 **)(uVar7 + 0x14);
            while (puVar3 != (undefined4 *)(uVar7 + 0x14)) {
              puVar2 = (undefined4 *)*puVar3;
              FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
              puVar3 = puVar2;
            }
            FUN_08adbc24(DAT_08be84a0,uVar7,0x1c);
            uVar7 = uVar6;
          }
          uVar7 = *(uint *)(uVar8 + 8);
          puVar3 = *(undefined4 **)(uVar8 + 0x14);
          while (puVar3 != (undefined4 *)(uVar8 + 0x14)) {
            puVar2 = (undefined4 *)*puVar3;
            FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
            puVar3 = puVar2;
          }
          FUN_08adbc24(DAT_08be84a0,uVar8,0x1c);
          uVar8 = uVar7;
        }
        uVar8 = *(uint *)(uVar9 + 8);
        puVar3 = *(undefined4 **)(uVar9 + 0x14);
        while (puVar3 != (undefined4 *)(uVar9 + 0x14)) {
          puVar2 = (undefined4 *)*puVar3;
          FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
          puVar3 = puVar2;
        }
        FUN_08adbc24(DAT_08be84a0,uVar9,0x1c);
        uVar9 = uVar8;
      }
      uVar9 = *(uint *)(local_3c + 8);
      puVar3 = *(undefined4 **)(local_3c + 0x14);
      while (puVar3 != (undefined4 *)(local_3c + 0x14)) {
        puVar2 = (undefined4 *)*puVar3;
        FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
        puVar3 = puVar2;
      }
      FUN_08adbc24(DAT_08be84a0,local_3c,0x1c);
      local_3c = uVar9;
    }
    uVar9 = *(uint *)(local_34 + 8);
    puVar3 = *(undefined4 **)(local_34 + 0x14);
    while (puVar3 != (undefined4 *)(local_34 + 0x14)) {
      puVar2 = (undefined4 *)*puVar3;
      FUN_08adbc24(DAT_08be84a0,(uint)puVar3,0xc);
      puVar3 = puVar2;
    }
    FUN_08adbc24(DAT_08be84a0,local_34,0x1c);
    local_34 = uVar9;
  }
  return;
}

// Nine differences are stack spill slot assignments under the primary profile; candidate retained.
// near miss from lane lbp2a (unreviewed)
