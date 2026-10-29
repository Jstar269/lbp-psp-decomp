/* LBPMATCH module=EBOOT.BIN start=0x08918074 end=0x08918144 symbol=FUN_08918074 lang=c99 */
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

extern int DAT_08bef4b0;
extern undefined * DAT_08bef4b4;
extern undefined4 DAT_08bef4c0;
extern undefined4 DAT_08bef4c4;
extern undefined4 DAT_08bef4d0;
extern void FUN_0891692c();
extern void FUN_089170c4();
extern void FUN_08917ac0();

void FUN_08918074(uint param_1,uint param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = DAT_08bef4b0;
  FUN_08917ac0(DAT_08bef4b0,param_2,param_1);
  for (iVar3 = 0; iVar3 < DAT_08bef4d0; iVar3 = iVar3 + 1) {
    piVar2 = (int *)(DAT_08bef4b4 + iVar3 * 0x10);
    if ((*piVar2 != 0) && (*(char *)piVar2[2] != '\0')) {
      FUN_0891692c(piVar1,iVar3,param_1,param_2);
      FUN_089170c4(piVar1,iVar3,param_1,param_2);
    }
  }
  DAT_08bef4c0 = param_1;
  DAT_08bef4c4 = param_2;
  return;
}

// Baseline generated candidate; 35 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
