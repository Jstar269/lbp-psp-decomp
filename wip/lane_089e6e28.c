/* LBPMATCH module=EBOOT.BIN start=0x089e6e28 end=0x089e6efc symbol=FUN_089e6e28 lang=c99 */
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

extern undefined DAT_08bdbd29;
extern void FUN_089e6cbc();
extern void FUN_08a9e0cc();
extern void FUN_08a9e11c();

void FUN_089e6e28(int *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (DAT_08bdbd29 == '\0') {
    FUN_089e6cbc(param_1);
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)param_1[1];
    }
    else {
      (*(code *)puVar2[5])(*puVar2);
      FUN_08a9e0cc((uint)puVar2);
      puVar2 = (undefined4 *)param_1[1];
    }
    *param_1 = 0;
    if (puVar2 != (undefined4 *)0x0) {
      (*(code *)puVar2[5])(*puVar2);
      FUN_08a9e0cc((uint)puVar2);
    }
    param_1[1] = 0;
    iVar3 = 1;
    do {
      if (param_1[0x32] != 0) {
        FUN_08a9e11c(param_1[0x32]);
        param_1[0x32] = 0;
      }
      if (param_1[0x33] == 1) {
        iVar1 = 3;
      }
      else {
        iVar1 = 4;
      }
      param_1[0x33] = iVar1;
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 8;
    } while (iVar3 != 4);
    DAT_08bdbd29 = '\x01';
  }
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.
// Indexed loop version was 25 words off versus this baseline at 23; register allocation and conditional assignment remain different.
// near miss from lane lbp1c (unreviewed)
