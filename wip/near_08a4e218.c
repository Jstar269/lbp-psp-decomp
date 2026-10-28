/* LBPMATCH module=EBOOT.BIN start=0x08a4e218 end=0x08a4e2a8 symbol=FUN_08a4e218 lang=c99 */
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
extern undefined4 FUN_08a50fbc();
extern undefined4 FUN_08a52bb8();
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

void FUN_08a4e218(int param_1,uint *param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_08a50fbc();
  iVar1 = FUN_08a52bb8(iVar1,param_2);
  piVar2 = *(int **)(param_1 + 0x30c);
  while( true ) {
    if ((int *)(param_1 + 0x30c) == piVar2) {
      return;
    }
    if (iVar1 == piVar2[2]) break;
    piVar2 = (int *)*piVar2;
  }
  FUN_08b88fc8(piVar2);
  FUN_08adbc24(DAT_08be84a0,(uint)piVar2,0xc);
  return;
}

// Primary profile differs by 26 words in loop layout; a compound while condition was also nonmatching.
// near miss from lane lbp2a (unreviewed)
