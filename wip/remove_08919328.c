/* LBPMATCH module=EBOOT.BIN start=0x08919328 end=0x089193dc symbol=FUN_08919328 lang=c99 */
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

extern void FUN_08916ffc();
extern void FUN_08919200();
extern void FUN_0891bde0();
extern void FUN_08a9e0cc();

void FUN_08919328(undefined4 *param_1,int param_2)
{
  undefined4 *puVar1;
  uint uVar2;
  uint local_20 [4];
  
  uVar2 = *(uint *)(param_2 + 0xb4);
  if (*(uchar *)(uVar2 + 0x20) != '\0') {
    FUN_08916ffc(*(int *)(uVar2 + 0x38));
    *(undefined4 *)(uVar2 + 0x38) = 0xffffffff;
    *(undefined1 *)(uVar2 + 0x20) = 0;
    *(undefined1 *)(uVar2 + 0x21) = 0;
  }
  puVar1 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      *(undefined4 *)(param_2 + 0xb4) = 0;
      return;
    }
    if (puVar1[2] == uVar2) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  local_20[0] = uVar2;
  FUN_08919200(param_1,(int *)local_20);
  uVar2 = local_20[0];
  if (local_20[0] == 0) {
    *(undefined4 *)(param_2 + 0xb4) = 0;
    return;
  }
  FUN_0891bde0(local_20[0]);
  FUN_08a9e0cc(uVar2);
  *(undefined4 *)(param_2 + 0xb4) = 0;
  return;
}

// 28 words differ; typed list loop gives different branch layout.
// near miss from lane lbp7a (unreviewed)
