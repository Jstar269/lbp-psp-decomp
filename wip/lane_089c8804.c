/* LBPMATCH module=EBOOT.BIN start=0x089c8804 end=0x089c88a8 symbol=FUN_089c8804 lang=c99 */
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

extern undefined * DAT_08be85fc;
extern undefined * FUN_0888289c();
extern void FUN_08970b6c();
extern void FUN_089745b8();
extern void FUN_089c8794();
extern undefined4 FUN_089ea4a4();

void FUN_089c8804(int param_1,undefined4 *param_2)
{
  undefined *puVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0xc) == 3) {
    uVar4 = *(undefined4 *)(DAT_08be85fc + 0x29c);
    puVar1 = FUN_0888289c();
    psVar2 = (short *)FUN_089ea4a4(uVar4,puVar1);
    FUN_089c8794(param_1,psVar2);
  }
  puVar3 = (undefined4 *)*param_2;
  if (puVar3 != (undefined4 *)0x0) {
    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + 1;
  }
  FUN_089745b8(param_1);
  if (puVar3 != (undefined4 *)0x0) {
    FUN_08970b6c(puVar3);
  }
  return;
}

// Initial primary-profile candidate: 27 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
