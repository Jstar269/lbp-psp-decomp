/* LBPMATCH module=EBOOT.BIN start=0x088efb24 end=0x088efbe8 symbol=FUN_088efb24 lang=c99 cc=gcc404xs-Os */
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

extern int FUN_088e6e1c();
extern int FUN_088e7d14();
extern void FUN_088ef50c();
extern void FUN_08a9df6c();
extern void FUN_08a9e0c4();
extern int FUN_08b89838();

void FUN_088efb24(uint *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int local_28;
  int local_2c;
  uint local_30;
  
  local_30 = *param_1;
  iVar1 = FUN_088e6e1c(0x8beedc4,&local_30);
  local_28 = FUN_088e7d14(0x8beedc4,&local_30);
  for (iVar2 = iVar1; iVar2 != local_28; iVar2 = FUN_08b89838(iVar2)) {
  }
  local_2c = iVar1;
  FUN_088ef50c(0x8beedc4,iVar1,local_28);
  if (*(uint *)(*param_1 + 0x2c) != 0) {
    FUN_08a9df6c(*(uint *)(*param_1 + 0x2c));
  }
  if (param_2 != 0) {
    FUN_08a9e0c4(param_2);
  }
  return;
}

// profile sweep: 25 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
