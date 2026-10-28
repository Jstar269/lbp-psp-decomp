/* LBPMATCH module=EBOOT.BIN start=0x089ab6c8 end=0x089ab74c symbol=FUN_089ab6c8 lang=c99 */
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

struct Item { int a,b,c; };
extern void FUN_088050b8(int *param_1);
extern void FUN_089ab578(int param_1,int *param_2,int param_3);

void FUN_089ab6c8(int param_1)
{
  uint uVar1;
  uint uVar2;
  int *local_20 [4];
  
  uVar1 = 0;
  while (uVar2 = uVar1 + 1,
        uVar1 < (uint)(*(struct Item **)(param_1 + 0x74) - *(struct Item **)(param_1 + 0x70))) {
    local_20[0] = (int *)0x0;
    FUN_089ab578((int)(param_1),(int *)((int *)local_20),(int)(uVar1));
    uVar1 = uVar2;
    if (local_20[0] != (int *)0x0) {
      FUN_088050b8((int *)(local_20[0]));
    }
  }
  return;
}


// Primary compiler has 22 differences from pointer-distance multiplication; using typed element pointers gave the same output.
// near miss from lane lbp2a (unreviewed)
