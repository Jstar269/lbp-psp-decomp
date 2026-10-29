/* LBPMATCH module=EBOOT.BIN start=0x088c17e8 end=0x088c1974 symbol=FUN_088c17e8 lang=c99 */
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

extern int * DAT_08bee5e8;
extern int * DAT_08bee5ec;
extern int * DAT_08bee5f0;
extern int * DAT_08bee5f4;
extern int * DAT_08bee5f8;
extern int * DAT_08bee5fc;
extern int * DAT_08bee600;
extern int * DAT_08bee604;
extern int * DAT_08bee608;
extern int * DAT_08bee60c;
extern int * DAT_08bee610;
extern void FUN_088050b8();

void FUN_088c17e8(void)
{
  bool bVar1;
  int *piVar2;
  
  if (DAT_08bee610 != (int *)0x0) {
    (**(code **)(*DAT_08bee610 + 4))();
    DAT_08bee610 = (int *)0x0;
  }
  if (DAT_08bee60c != (int *)0x0) {
    (**(code **)(*DAT_08bee60c + 4))();
    DAT_08bee60c = (int *)0x0;
  }
  if (DAT_08bee608 != (int *)0x0) {
    (**(code **)(*DAT_08bee608 + 4))();
    DAT_08bee608 = (int *)0x0;
  }
  if (DAT_08bee604 != (int *)0x0) {
    (**(code **)(*DAT_08bee604 + 4))();
    DAT_08bee604 = (int *)0x0;
  }
  if (DAT_08bee600 != (int *)0x0) {
    (**(code **)(*DAT_08bee600 + 4))();
    DAT_08bee600 = (int *)0x0;
  }
  if (DAT_08bee5fc != (int *)0x0) {
    (**(code **)(*DAT_08bee5fc + 4))();
    DAT_08bee5fc = (int *)0x0;
  }
  if (DAT_08bee5f8 != (int *)0x0) {
    (**(code **)(*DAT_08bee5f8 + 4))();
    DAT_08bee5f8 = (int *)0x0;
  }
  if (DAT_08bee5f4 != (int *)0x0) {
    (**(code **)(*DAT_08bee5f4 + 4))();
    DAT_08bee5f4 = (int *)0x0;
  }
  piVar2 = DAT_08bee5f0;
  bVar1 = DAT_08bee5f0 != (int *)0x0;
  DAT_08bee5f0 = (int *)0x0;
  if (bVar1) {
    FUN_088050b8(piVar2);
  }
  piVar2 = DAT_08bee5ec;
  bVar1 = DAT_08bee5ec != (int *)0x0;
  DAT_08bee5ec = (int *)0x0;
  if (bVar1) {
    FUN_088050b8(piVar2);
  }
  piVar2 = DAT_08bee5e8;
  bVar1 = DAT_08bee5e8 == (int *)0x0;
  DAT_08bee5e8 = (int *)0x0;
  if (bVar1) {
    return;
  }
  FUN_088050b8(piVar2);
  return;
}

// NEAR: 24 differing words; primary and O2 profiles tested.
// near miss from lane lbp5b (unreviewed)
