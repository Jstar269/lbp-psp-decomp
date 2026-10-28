/* LBPMATCH module=EBOOT.BIN start=0x089adc4c end=0x089adcb8 symbol=FUN_089adc4c lang=c99 cc=gcc404xs-Os */
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
typedef float undefined4;

extern undefined4 * FUN_088263a4();
extern void FUN_089ada48();

void FUN_089adc4c(int param_1,int param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  puVar2 = FUN_088263a4(param_2);
  uVar3 = puVar2[2];
  *(undefined4 **)(param_1 + 0x8c) = puVar2;
  *(undefined4 *)(param_1 + 0x78) = uVar3;
  uVar3 = puVar2[1];
  *(undefined4 *)(param_1 + 0x70) = uVar3;
  *(undefined4 *)(param_1 + 0x74) = uVar3;
  FUN_089ada48(param_1);
  return;
}

// residual: same float pair as 0x089acd84 but here the emission ignores source order (both orders give 116 then 112). parked.
// near miss from lane lbp2b (unreviewed)
