/* LBPMATCH module=EBOOT.BIN start=0x089de3fc end=0x089de448 symbol=FUN_089de3fc lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3b, Claude Sonnet 5.5): added the object argument to the virtual call; exact match verified; names and types await human review. */
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


void FUN_089de3fc(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
      puVar1 = (undefined4 *)*puVar1) {
    (**(void (**)(int))(*(int *)puVar1[2] + 0x50))(puVar1[2]);
  }
  return;
}
