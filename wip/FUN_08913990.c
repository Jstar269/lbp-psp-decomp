/* LBPMATCH module=EBOOT.BIN start=0x08913990 end=0x089139b4 symbol=FUN_08913990 lang=c99 */
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


void FUN_08913990(undefined1 *param_1)
{
  *(undefined1 **)(param_1 + 8) = param_1 + 4;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x10) = 0x400;
  param_1[0x14] = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined1 **)(param_1 + 4) = param_1 + 4;
  return;
}

// 3 words differ: store ordering and address base after source-order permutations.
// near miss from lane lbp5a (unreviewed)
