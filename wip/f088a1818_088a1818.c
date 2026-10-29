/* LBPMATCH module=EBOOT.BIN start=0x088a1818 end=0x088a183c symbol=FUN_088a1818 lang=c99 */
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


void FUN_088a1818(int param_1,int param_2)
{
  *(undefined4 *)(*(int *)(param_1 + 8) + param_2 * 4) = *(undefined4 *)(param_1 + 0xc);
  return;
}

// 9 words differ: shared entry thunk jumps into same range; straight C folds adjustment.
// near miss from lane lbp15a (unreviewed)
