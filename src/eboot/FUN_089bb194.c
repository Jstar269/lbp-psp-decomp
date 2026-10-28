/* LBPMATCH module=EBOOT.BIN start=0x089bb194 end=0x089bb1bc symbol=FUN_089bb194 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08beed14;
extern int * FUN_089b34dc();

void FUN_089bb194(int param_1,uint param_2)
{
  FUN_089b34dc(*(undefined4 *)
                (*(int *)(*(int *)(param_1 + 0x14) + 0x28) +
                *(short *)(*(int *)(param_1 + 0x14) + 0x2c) * -4),param_2,DAT_08beed14 + 0x40);
  return;
}
