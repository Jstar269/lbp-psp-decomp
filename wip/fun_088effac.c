/* LBPMATCH module=EBOOT.BIN start=0x088effac end=0x088f005c symbol=FUN_088effac lang=c99 */
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

extern char DAT_08beedc4;
extern int FUN_088e6e1c();
extern int FUN_088e7d14();
extern void FUN_088ef50c();
extern void FUN_08921170();
extern int FUN_08b89838();

void FUN_088effac(uint *param_1)
{
  int iVar1;
  int iVar2;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = *param_1;
  iVar1 = FUN_088e6e1c(&DAT_08beedc4,&local_20);
  local_14 = FUN_088e7d14(&DAT_08beedc4,&local_20);
  for (iVar2 = iVar1; iVar2 != local_14; iVar2 = FUN_08b89838(iVar2)) {
  }
  local_18 = iVar1;
  FUN_088ef50c(&DAT_08beedc4,iVar1,local_14);
  local_1c = *(int *)(*param_1 + 0x2c);
  if (local_1c != 0) {
    FUN_08921170(param_1,&local_1c,0);
  }
  return;
}


// Os 23 words differ; local copies before erase are optimized away; calling convention needs investigation.
// near miss from lane lbp8e (unreviewed)
