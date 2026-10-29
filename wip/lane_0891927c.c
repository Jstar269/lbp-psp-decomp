/* LBPMATCH module=EBOOT.BIN start=0x0891927c end=0x08919328 symbol=FUN_0891927c lang=c99 */
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

void FUN_0891927c(undefined4 *param_1,int param_2)
{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint local_20 [4];
  
  cVar1 = *(char *)(param_2 + 0x20);
  *(undefined4 *)(*(int *)(param_2 + 0x2c) + 0xb4) = 0;
  if (cVar1 != '\0') {
    FUN_08916ffc(*(int *)(param_2 + 0x38));
    *(undefined4 *)(param_2 + 0x38) = 0xffffffff;
    *(undefined1 *)(param_2 + 0x20) = 0;
    *(undefined1 *)(param_2 + 0x21) = 0;
  }
  puVar3 = (undefined4 *)*param_1;
  while( true ) {
    if (puVar3 == param_1) {
      return;
    }
    if (puVar3[2] == param_2) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  local_20[0] = param_2;
  FUN_08919200(param_1,(int *)local_20);
  uVar2 = local_20[0];
  if (local_20[0] == 0) {
    return;
  }
  FUN_0891bde0(local_20[0]);
  FUN_08a9e0cc(uVar2);
  return;
}

// Initial primary-profile candidate: 28 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
