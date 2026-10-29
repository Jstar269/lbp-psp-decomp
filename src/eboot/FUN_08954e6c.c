/* LBPMATCH module=EBOOT.BIN start=0x08954e6c end=0x08954ee0 symbol=FUN_08954e6c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): swapped the two running-total updates (+4 before +0x14); exact match verified; names and types await human review. */
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

extern undefined4 * FUN_08b9e7a8();

void FUN_08954e6c(int param_1,undefined4 *param_2,int param_3,int param_4)
{
  if (*(uchar *)(*(int *)(param_1 + 0x30) + 0xc) == '\0') {
    FUN_08b9e7a8(*(undefined4 **)(param_1 + 4),param_2,param_3 * param_4);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_3 * param_4;
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_3 * param_4;
  return;
}
