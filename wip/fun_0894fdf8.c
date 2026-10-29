/* LBPMATCH module=EBOOT.BIN start=0x0894fdf8 end=0x0894feb0 symbol=FUN_0894fdf8 lang=c99 */
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
extern undefined4 * FUN_0894b128();
extern int FUN_0894b27c();
extern void FUN_0894b568();
extern undefined4 FUN_08adbb84();
extern void FUN_08b88fac();

void FUN_0894fdf8(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  undefined4 local_30 [4];
  
  if (param_3 == 0) {
    local_30[0] = 0;
    FUN_0894b568(param_2,local_30,4,1);
  }
  else {
    iVar1 = FUN_0894b27c((int)param_2);
    piVar2 = (int *)FUN_08adbb84(DAT_08be84a0,0xc);
    if ((char *)piVar2 + 0x8 != (char *)0) {
      piVar2[2] = iVar1;
    }
    FUN_08b88fac(piVar2,param_1 + 0x24);
    FUN_0894b128((int)param_2,param_3,1,4,1);
  }
  return;
}

// Baseline generated candidate; 32 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
