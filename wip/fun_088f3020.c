/* LBPMATCH module=EBOOT.BIN start=0x088f3020 end=0x088f30c4 symbol=FUN_088f3020 lang=c99 */
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

extern void FUN_088ef6c0();
extern undefined * DAT_08be85fc;
extern void FUN_088dfd64();
extern int FUN_088e053c();
extern void FUN_088f2774();
extern void FUN_08a9bff8();
extern void FUN_08a9c014();

void FUN_088f3020(undefined4 param_1,undefined4 *param_2)
{
  int iVar1;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_30;
  undefined4 local_2c;
  
  local_40 = 0;
  iVar1 = FUN_088e053c(param_2,&local_40);
  if (iVar1 != 0) {
    FUN_08a9c014(&local_30);
    FUN_088dfd64(&local_30,*(undefined4 *)(DAT_08be85fc + 0x29c));
    local_3c = local_30;
    local_38 = local_2c;
    FUN_088f2774(param_1,&local_3c,iVar1,FUN_088ef6c0,local_40,local_40);
    FUN_08a9bff8((int)&local_30);
  }
  return;
}


// Os 27 words differ; paired stack object and copied arguments need reconstruction.
// near miss from lane lbp8e (unreviewed)
