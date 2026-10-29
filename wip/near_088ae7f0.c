/* LBPMATCH module=EBOOT.BIN start=0x088ae7f0 end=0x088ae89c symbol=FUN_088ae7f0 lang=c99 */
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

extern int DAT_08be84a0;
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

void FUN_088ae7f0(int *param_1, unsigned short param_2, unsigned short param_3)
{
  int *piVar1;
  int iVar2;
  int *piVar3;

  piVar1 = (int *)*param_1;
  while (piVar3 = piVar1, piVar1 = piVar3 + 2, piVar3 != param_1) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      if (*(unsigned short *)piVar1 == param_2) {
        *(unsigned short *)piVar1 = param_3;
      }
      piVar1 = (int *)((int)piVar1 + 2);
    } while (iVar2 != 2);
    piVar1 = (int *)*piVar3;
    if (*(unsigned short *)((int)piVar3 + 10) == (unsigned short)piVar3[2]) {
      FUN_08b88fc8(piVar3);
      FUN_08adbc24(DAT_08be84a0, piVar3, 12);
    }
  }
}
// NEAR: unsigned short params/loads fixed the seh/lh; remaining: retail loads +10 via a1 (lhu 2(a1)) and +8 via s0, ours the reverse; 'move a0,zero; li a2,2; move v1,a1' ordering. Tried operand swaps, (ushort*)(p+2)[1], separate loop pointer, struct version.
// near miss from lane lbp4c (unreviewed)
