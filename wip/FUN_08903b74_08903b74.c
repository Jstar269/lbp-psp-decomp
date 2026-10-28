/* LBPMATCH module=EBOOT.BIN start=0x08903b74 end=0x08903c2c symbol=FUN_08903b74 lang=c99 cc=gcc404xs-Os */
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

extern bool FUN_08931120();
extern undefined8 FUN_08a9b8a4();
extern void FUN_08a9bff8();
extern undefined4 * FUN_08a9d390();
extern uint FUN_08a9d790();

void FUN_08903b74(int *param_1,undefined4 *param_2)
{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  int local_50;
  uint *local_4c;
  undefined4 local_48;
  uint *local_44;
  undefined4 local_40;
  undefined4 auStack_38 [6];
  
  local_50 = 0;
  FUN_08931120(*(uint *)(*param_1 + 0xc),&local_50);
  if (local_50 == 5) {
    puVar2 = *(uint **)(*param_1 + 0x1c);
    uVar3 = FUN_08a9b8a4(&local_44,puVar2);
    local_40 = (undefined4)uVar3;
    local_44 = puVar2;
    uVar1 = FUN_08a9d790(&local_44);
    uVar3 = FUN_08a9b8a4(&local_4c,puVar2);
    local_48 = (undefined4)uVar3;
    local_4c = puVar2;
    FUN_08a9d390(auStack_38,uVar1);
    FUN_08a9bff8((int)auStack_38);
    *param_2 = uVar1;
  }
  return;
}

// profile sweep: 25 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
