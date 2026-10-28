/* LBPMATCH module=EBOOT.BIN start=0x08811f34 end=0x08811fc8 symbol=FUN_08811f34 lang=c99 cc=gcc171-Os */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_08bdc1cc;
extern undefined4 DAT_08bdc1d0;
extern void FUN_08811e14();
extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a52bb8();

void FUN_08811f34(int param_1)
{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x90) != -1) {
    iVar1 = FUN_08a50fbc();
    piVar2 = (int *)FUN_08a52bb8(iVar1,(uint *)(param_1 + 0x90));
    if (((piVar2 != (int *)0x0) && (piVar2[0x11] == 0x23)) &&
       (((float)piVar2[0xc] <= DAT_08bdc1d0 || (DAT_08bdc1cc < (float)piVar2[0xc])))) {
      FUN_08811e14(piVar2);
      return;
    }
  }
  return;
}

// profile sweep: 20 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
