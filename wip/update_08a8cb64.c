/* LBPMATCH module=EBOOT.BIN start=0x08a8cb64 end=0x08a8cc4c symbol=FUN_08a8cb64 lang=c99 cc=gcc404xs-O2 */
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

extern void FUN_08804f3c();
extern undefined * FUN_089ecaa8();
extern void FUN_08a322a4();
extern void FUN_08a8c964();
extern int * FUN_08a9c5b0();
extern uint FUN_08a9d790();

void FUN_08a8cb64(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  int *local_20 [4];
  
  if (*(int *)(param_1 + 0x2f4) != 0) {
    FUN_08a322a4(param_1,*(int *)(param_1 + 0x2f4));
  }
  FUN_08a9c5b0((int *)(param_1 + 0x300),param_2);
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x2f8) = 1;
    *(undefined4 *)(param_1 + 0x2f4) = 0;
    FUN_08a8c964(param_1);
    return;
  }
  uVar2 = FUN_08a9d790((undefined4 *)param_2);
  *(uint *)(param_1 + 0x2f4) = uVar2;
  *(undefined1 *)(param_1 + 0x2f8) = 0;
  puVar3 = FUN_089ecaa8();
  (**(code **)(*(int *)(puVar3 + 0x9c) + 0x38))(local_20,puVar3 + 0x9c);
  (**(code **)(*local_20[0] + 0x2c))(local_20[0],uVar2);
  FUN_08804f3c(local_20);
  FUN_08a8c964(param_1);
  return;
}


// 34 words differ under O2; virtual calls and duplicated control flow need C++ reconstruction.
// near miss from lane lbp7a (unreviewed)
