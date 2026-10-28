/* LBPMATCH module=EBOOT.BIN start=0x08a51d20 end=0x08a51dec symbol=FUN_08a51d20 lang=c99 cc=gcc402x-O2 */
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

extern undefined DAT_08bd6488;
extern undefined4 DAT_08be84a0;
extern undefined8 FUN_08a9b8a4();
extern uint FUN_08a9d790();
extern undefined4 FUN_08adbb84();
extern void FUN_08b88fac();

void FUN_08a51d20(int param_1)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  undefined *local_20;
  undefined4 local_1c;
  undefined *local_18;
  undefined4 local_14;
  
  iVar3 = *(int *)(param_1 + 0xb44);
  if ((iVar3 != 0) && (*(int *)(*(int *)(iVar3 + 4) + 8) != 0)) {
    uVar4 = FUN_08a9b8a4(&local_18,(uint *)&DAT_08bd6488);
    local_14 = (undefined4)uVar4;
    local_18 = &DAT_08bd6488;
    uVar1 = FUN_08a9d790(&local_18);
    uVar4 = FUN_08a9b8a4(&local_20,(uint *)&DAT_08bd6488);
    local_1c = (undefined4)uVar4;
    local_20 = &DAT_08bd6488;
    piVar2 = (int *)FUN_08adbb84(DAT_08be84a0,0xc);
    if ((char *)piVar2 + 0x8 != (char *)0) {
      piVar2[2] = uVar1;
    }
    FUN_08b88fac(piVar2,iVar3);
    return;
  }
  return;
}

// profile sweep: 27 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
