/* LBPMATCH module=EBOOT.BIN start=0x089f9764 end=0x089f9820 symbol=FUN_089f9764 lang=c99 rodata=0x08bc2bc0 */
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

extern undefined * DAT_08be84a4;
extern void FUN_088105d0();
extern int FUN_08a9f058();

void FUN_089f9764(char *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  char *iVar4;
  
  piVar3 = *(int **)(param_1 + 0x2828);
  iVar1 = FUN_08a9f058(*piVar3 << 2,0x10,
                       "void OneFramePointerHeap<T>::AllocInternal() [with T = CompoundObject*]",
                       0x34);
  iVar4 = DAT_08be84a4;
  piVar3[2] = iVar1;
  iVar1 = FUN_08a9f058(0x2c000,0x10,0,0);
  *(int *)(iVar4 + 0x571c) = iVar1;
  iVar4 = 0;
  do {
    puVar2 = (undefined4 *)(iVar4 + *(int *)(DAT_08be84a4 + 0x571c));
    iVar4 = iVar4 + 0xb0;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_088105d0(puVar2);
    }
  } while (iVar4 != 0x2c000);
  *(undefined1 *)(param_1 + 0x282c) = 0;
  return;
}

// Primary profile: 43 differing aligned words, 45/47 words; loop register allocation and saved registers differ from retail. Generated candidate was one word off under older profile.
// near miss from lane lbp1b (unreviewed)
