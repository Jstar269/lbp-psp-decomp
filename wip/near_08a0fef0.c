/* LBPMATCH module=EBOOT.BIN start=0x08a0fef0 end=0x08a0ff38 symbol=FUN_08a0fef0 lang=c99 */
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

extern undefined4 * FUN_08a10f1c();

void FUN_08a0fef0(uint *param_1,uint param_2)
{
  undefined4 *puVar1;
  
  puVar1 = FUN_08a10f1c();
  if ((uint *)puVar1[1] != param_1) {
    *param_1 = param_2 | *param_1;
  }
  return;
}

// Two words differ in the register selected for the pointer comparison under the primary compiler.
// near miss from lane lbp2a (unreviewed)
