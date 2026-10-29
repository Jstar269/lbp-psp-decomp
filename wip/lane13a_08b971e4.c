/* LBPMATCH module=EBOOT.BIN start=0x08b971e4 end=0x08b97284 symbol=FUN_08b971e4 lang=c99 */
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

extern void FUN_08b978f8();
extern int FUN_08b97a24();

undefined4 FUN_08b971e4(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)
{
  int iVar1;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40 [6];
  uint local_28 [6];
  
  local_50 = param_1;
  local_4c = param_2;
  local_48 = param_3;
  local_44 = param_4;
  FUN_08b978f8(&local_50,local_40);
  FUN_08b978f8(&local_48,local_28);
  if ((1 < local_40[0]) && (1 < local_28[0])) {
    iVar1 = FUN_08b97a24(local_40,local_28);
    return iVar1;
  }
  return 0xffffffff;
}
// 38 words differ; long long parameters also failed to reproduce argument homes and control flow.
// near miss from lane lbp13a (unreviewed)
