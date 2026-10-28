/* LBPMATCH module=EBOOT.BIN start=0x088ae998 end=0x088aea18 symbol=FUN_088ae998 lang=c99 */
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

extern undefined4 DAT_08be84a0;
extern undefined4 FUN_08adbb84();
extern void FUN_08b88fac();

void FUN_088ae998(int param_1,undefined4 *param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  
  *(int *)param_1 = param_1;
  puVar2 = (undefined4 *)*param_2;
  *(int *)(param_1 + 4) = param_1;
  for (; puVar2 != param_2; puVar2 = (undefined4 *)*puVar2) {
    piVar1 = (int *)FUN_08adbb84(DAT_08be84a0,0xc);
    if ((char *)piVar1 + 0x8 != (char *)0) {
      *(undefined2 *)(piVar1 + 2) = *(undefined2 *)(puVar2 + 2);
    }
    FUN_08b88fac(piVar1,param_1);
  }
  return;
}

// 2 words left at +0x40: retail emits addiu v0,v0,8 / beqz, i.e. it keeps the address
// computation and tests it; GCC 4.0.4 folds `p + 8 != 0` to `p != -8` (li v0,-8 / beq) for
// every spelling tried: explicit != (char*)0, bare `if (p + 8)`, a typed (undefined2*)(p+2),
// and the folded compare written out. The add survives only if the compare target is opaque,
// which the retail code does not show.
// near miss from lane lbp2b (unreviewed)
