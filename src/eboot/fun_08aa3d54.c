/* LBPMATCH module=EBOOT.BIN start=0x08aa3d54 end=0x08aa3e04 symbol=FUN_08aa3d54 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp8e, Codex GPT-6): reconstructed nested loops; exact match verified; names and types await human review. */
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


void FUN_08aa3d54(int *param_1,int param_2,int param_3,uint param_4,uint param_5,undefined4 param_6)
{
  uint y, x;
  for (y = 0; y < param_5; ++y) {
    for (x = 0; x < param_4; ++x) {
      (**(code **)(*param_1 + 0x10))(param_1, x + param_2, y + param_3, param_6);
    }
  }
  return;
}



