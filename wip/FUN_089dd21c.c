/* LBPMATCH module=EBOOT.BIN start=0x089dd21c end=0x089dd240 symbol=FUN_089dd21c lang=c99 */
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


void FUN_089dd21c(int param_1,unsigned char param_2)
{
  undefined4 uVar1;
  
  uVar1 = param_2 ? 0xff000000 : 0xffffffff;
  if (*(int *)(param_1 + 0x40) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xb0) = uVar1;
  }
  *(char *)(param_1 + 0x4c) = param_2;
  return;
}


// 2 words differ: immediate load and argument truncation scheduling.
// near miss from lane lbp5a (unreviewed)
