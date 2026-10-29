/* LBPMATCH module=EBOOT.BIN start=0x08a9c268 end=0x08a9c304 symbol=FUN_08a9c268 lang=c99 rodata=0x08bcabfc */
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

extern void FUN_08a9c164();

int * FUN_08a9c268(int *param_1,uint param_2,uint param_3)
{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_20 [4];
  
  puVar3 = local_20;
  uVar6 = 0xf0000000;
  uVar5 = 0x1c;
  uVar4 = 8;
  do {
    if (((param_2 & uVar6) != 0) || (uVar4 <= param_3)) break;
    uVar5 = uVar5 - 4;
    uVar6 = uVar6 >> 4;
    uVar4 = uVar4 - 1;
  } while (uVar5 != 0);
  while( true ) {
    uVar2 = param_2 & uVar6;
    uVar1 = uVar5 & 0x1f;
    uVar6 = uVar6 >> 4;
    uVar5 = uVar5 - 4;
    if (puVar3 == (uint *)((int)local_20 + uVar4)) break;
    *(char *)puVar3 = "0123456789ABCDEF"[uVar2 >> uVar1];
    puVar3 = (uint *)((int)puVar3 + 1);
  }
  *(char *)puVar3 = '\0';
  FUN_08a9c164(param_1,local_20);
  return param_1;
}

// 22 differing words; natural loop and named end changed code layout without improvement.
// near miss from lane lbp7a (unreviewed)
