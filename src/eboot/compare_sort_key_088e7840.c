/* LBPMATCH module=EBOOT.BIN start=0x088e7840 end=0x088e787c symbol=FUN_088e7840 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp4c, Claude Sonnet 5.5): rewritten as a flag-test-or, with comparisons written param_2[i] > param_3[i] (operand order sets the sltu registers); exact match verified; names and types await human review. */
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


bool FUN_088e7840(undefined4 param_1,uint *param_2,uint *param_3)
{
  if ((*param_2 & 0x1000) != 0 || (*param_3 & 0x1000) != 0) {
    return param_2[3] > param_3[3];
  }
  return param_2[0x1c] > param_3[0x1c];
}
