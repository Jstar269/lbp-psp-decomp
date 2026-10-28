/* LBPMATCH module=EBOOT.BIN start=0x0889dfe0 end=0x0889e088 symbol=FUN_0889dfe0 lang=c99 */
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

extern void FUN_0889df18();
extern void FUN_08a9bff8();
extern void FUN_08a9e0cc();

void FUN_0889dfe0(int *param_1)
{
  int iVar1;
  int iVar2;
  
  FUN_0889df18(param_1);
  if (param_1[0xf] != 0) {
    FUN_08a9e0cc(param_1[0xf]);
  }
  for (iVar1 = param_1[0xc]; iVar1 != param_1[0xd]; iVar1 = iVar1 + 4) {
  }
  if (param_1[0xc] != 0) {
    FUN_08a9e0cc(param_1[0xc]);
  }
  iVar2 = param_1[10];
  for (iVar1 = param_1[9]; iVar1 != iVar2; iVar1 = iVar1 + 0x18) {
    FUN_08a9bff8(iVar1);
  }
  if (param_1[9] == 0) {
    return;
  }
  FUN_08a9e0cc(param_1[9]);
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.
// Revisited: vector base locals changed register allocation and increased mismatch from 17 to 19; preserve baseline.
// near miss from lane lbp1c (unreviewed)
