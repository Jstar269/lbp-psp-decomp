/* LBPMATCH module=EBOOT.BIN start=0x089acd84 end=0x089acdf8 symbol=FUN_089acd84 lang=c99 cc=gcc404xs-Os */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2b, DeepSeek through Freebuff): the two swc1 stores of one float to +0x70 and +0x74 are written in the opposite order in the translation, and retail emits the lower offset first; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_088263a4();
extern float FUN_088267cc();
extern float FUN_08826888();
extern void FUN_089acc58();

void FUN_089acd84(int param_1,int param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  float fVar3;
  
  piVar1 = *(int **)(param_1 + 0xd8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  puVar2 = FUN_088263a4(param_2);
  *(undefined4 **)(param_1 + 0xd8) = puVar2;
  fVar3 = FUN_088267cc(param_2);
  *(float *)(param_1 + 0x78) = fVar3;
  fVar3 = FUN_08826888(param_2);
  *(float *)(param_1 + 0x74) = fVar3;
  *(float *)(param_1 + 0x70) = fVar3;
  FUN_089acc58(param_1);
  return;
}
