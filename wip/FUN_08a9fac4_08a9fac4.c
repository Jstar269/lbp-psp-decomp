/* LBPMATCH module=EBOOT.BIN start=0x08a9fac4 end=0x08a9fc14 symbol=FUN_08a9fac4 lang=c99 cc=gcc410-Os */
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

extern void FUN_08a9e0cc();

void FUN_08a9fac4(undefined4 param_1,uint param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_3c;
  
  local_3c = param_2;
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
                uVar3 = *(uint *)(uVar4 + 0xc);
                while (uVar3 != 0) {
                  uVar2 = *(uint *)(uVar3 + 0xc);
                  while (uVar2 != 0) {
                    FUN_08a9fac4(param_1,*(uint *)(uVar2 + 0xc));
                    uVar1 = *(uint *)(uVar2 + 8);
                    FUN_08a9e0cc(uVar2);
                    uVar2 = uVar1;
                  }
                  uVar2 = *(uint *)(uVar3 + 8);
                  FUN_08a9e0cc(uVar3);
                  uVar3 = uVar2;
                }
                uVar3 = *(uint *)(uVar4 + 8);
                FUN_08a9e0cc(uVar4);
                uVar4 = uVar3;
              }
              uVar4 = *(uint *)(uVar5 + 8);
              FUN_08a9e0cc(uVar5);
              uVar5 = uVar4;
            }
            uVar5 = *(uint *)(uVar6 + 8);
            FUN_08a9e0cc(uVar6);
            uVar6 = uVar5;
          }
          uVar6 = *(uint *)(uVar7 + 8);
          FUN_08a9e0cc(uVar7);
          uVar7 = uVar6;
        }
        uVar7 = *(uint *)(uVar8 + 8);
        FUN_08a9e0cc(uVar8);
        uVar8 = uVar7;
      }
      uVar8 = *(uint *)(uVar9 + 8);
      FUN_08a9e0cc(uVar9);
      uVar9 = uVar8;
    }
    uVar9 = *(uint *)(local_3c + 8);
    FUN_08a9e0cc(local_3c);
    local_3c = uVar9;
  }
  return;
}

// residual: the two incoming-arg home slots are swapped: ours stores a0 at 4(sp)/a1 at 0(sp), retail a0 at 0(sp)/a1 at 4(sp);
// every later load mirrors. only one named local exists, so the swap is the allocator's, not a declaration order. parked.
// near miss from lane lbp2b (unreviewed)
