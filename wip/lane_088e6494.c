/* LBPMATCH module=EBOOT.BIN start=0x088e6494 end=0x088e657c symbol=FUN_088e6494 lang=c99 */
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

extern undefined4 DAT_08be85f8;
extern undefined * DAT_08bf03b8;
extern undefined4 FUN_088a1444();
extern void FUN_088a3ffc();
extern void FUN_088a4124();
extern void FUN_08968924();
extern void FUN_0896ee90();
extern undefined4 FUN_0896f7d0();
extern void FUN_08970494();

void FUN_088e6494(undefined4 param_1,uchar param_2)
{
  int iVar1;
  
  iVar1 = FUN_088a1444();
  if ((*(int *)(iVar1 + 0x138) == 2) && (iVar1 = FUN_088a1444(), *(int *)(iVar1 + 0x13c) < 5)) {
    if (param_2 == '\0') {
      iVar1 = FUN_088a1444();
      FUN_088a3ffc(iVar1);
      return;
    }
    iVar1 = FUN_088a1444();
    FUN_088a4124(iVar1);
    iVar1 = FUN_0896f7d0(DAT_08bf03b8);
    if (iVar1 == 0x4a) {
      FUN_0896ee90(DAT_08bf03b8,1,0x4a);
    }
    iVar1 = FUN_0896f7d0(DAT_08bf03b8);
    if (iVar1 != 0x4d) {
      FUN_08970494(DAT_08bf03b8,1,0x4d);
      FUN_08968924(DAT_08be85f8,1);
      *(undefined1 *)(DAT_08bf03b8 + 0x8c) = 0;
    }
  }
  return;
}

// Initial primary-profile candidate: 36 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
