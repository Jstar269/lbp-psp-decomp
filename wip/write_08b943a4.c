/* LBPMATCH module=EBOOT.BIN start=0x08b943a4 end=0x08b94454 symbol=FUN_08b943a4 lang=c99 */
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

extern void FUN_08b912fc();
extern void FUN_08b91810();
extern undefined4 * FUN_08b9e7a8();

void FUN_08b943a4(uint *param_1,int *param_2)
{
  int iVar1;
  
  if (*param_2 != 0x27) {
    FUN_08b91810(param_1,param_2);
    return;
  }
  iVar1 = param_2[1];
  if (param_1[1] != 0) {
    if (param_1[2] + *(uint *)(iVar1 + 8) <= param_1[3]) {
      FUN_08b9e7a8((undefined4 *)(param_1[1] + param_1[2]),*(undefined4 **)(iVar1 + 4),
                   *(uint *)(iVar1 + 8));
      param_1[2] = param_1[2] + *(int *)(param_2[1] + 8);
      return;
    }
  }
  FUN_08b912fc((int)param_1,*(undefined4 *)(iVar1 + 4),*(int *)(iVar1 + 8));
  return;
}



// 26 words differ under Os; O2 increases size and differences.
// near miss from lane lbp7a (unreviewed)
