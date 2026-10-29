/* LBPMATCH module=EBOOT.BIN start=0x08a4402c end=0x08a440b4 symbol=FUN_08a4402c lang=c99 */
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

extern void FUN_08adb8a4();

void FUN_08a4402c(int param_1)
{
  undefined4 *puVar1;
  
  if (*(uchar *)(param_1 + 8) != '\0') {
    puVar1 = *(undefined4 **)(param_1 + 0x78);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1);
      FUN_08adb8a4(puVar1);
    }
    puVar1 = *(undefined4 **)(param_1 + 0x7c);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1);
      FUN_08adb8a4(puVar1);
      return;
    }
  }
  return;
}
// 4 words differ: both virtual calls (slot 0, this passed) load the slot into v1 in retail (lw v1,0(v0); jalr v1), ours reuses v0. Same as 0x08a346e0.
// tried: C++ class with a virtual method, plain C pointer form, this passed explicitly: all give v0
// near miss from lane lbp3c (unreviewed)
