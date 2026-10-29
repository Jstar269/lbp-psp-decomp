/* LBPMATCH module=EBOOT.BIN start=0x088658d8 end=0x08865994 symbol=FUN_088658d8 lang=c99 rodata=0x08baff68 */
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

extern void FUN_08865170();
extern void FUN_08865280();
extern void FUN_088655c0();
extern void FUN_088656f4();

undefined4 FUN_088658d8(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  switch(*(undefined4 *)(param_1 + 200)) {
  case 1:
    FUN_088655c0(param_1);
    FUN_08865280(param_1);
    uVar2 = 0;
    break;
  case 2:
    iVar1 = *(int *)(*(int *)(param_1 + 0x274) + 0x10);
    if (iVar1 == 4) {
      uVar2 = 0;
      *(undefined4 *)(param_1 + 200) = 4;
    }
    else {
      uVar2 = 0;
      if (iVar1 == 6) {
        *(undefined4 *)(param_1 + 200) = 3;
      }
    }
    break;
  case 3:
    FUN_088656f4(param_1);
    FUN_08865170(param_1);
  default:
    uVar2 = 0;
    break;
  case 4:
  case 5:
    uVar2 = 1;
  }
  return uVar2;
}



// Os 34 differing words; jump-table case layout and nested pointer arithmetic differ; O2 52.
// near miss from lane lbp8e (unreviewed)
