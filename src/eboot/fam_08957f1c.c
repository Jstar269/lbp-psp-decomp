/* LBPMATCH module=EBOOT.BIN start=0x08957f1c end=0x08957f90 symbol=FUN_08957f1c lang=c99 */
/* Clone of src/eboot/fam_0894c42c.c (lbpclone.py tag c15): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp1a, Codex GPT-6): reverse conditional source order; exact match verified; names and types await human review. */
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


undefined4 FUN_08957f1c(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,uchar param_5)
{
  if (param_5) {
    (**(code **)(*(int *)param_1[0x2a] + 0x10))((int *)param_1[0x2a]);
    *(undefined1 *)(param_1 + 4) = 1;
    *param_3 = 0;
  }
  else {
    (**(code **)(*param_1 + 0x14))(param_1,param_3);
  }
  return 1;
}



