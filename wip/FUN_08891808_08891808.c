/* LBPMATCH module=EBOOT.BIN start=0x08891808 end=0x088918b8 symbol=FUN_08891808 lang=c99 cc=gcc404xs-Os */
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

extern void FUN_08887480();
extern undefined4 FUN_08ad07e0();
extern undefined4 FUN_08ad0900();
extern undefined4 FUN_08ad0990();
extern undefined4 FUN_08ad09bc();
extern undefined4 FUN_08ad09f8();

void FUN_08891808(undefined4 *param_1,char *param_2,undefined4 param_3,undefined4 param_4, uint param_5)
{
  uint *puVar1;
  undefined4 local_30 [4];
  
  puVar1 = param_1 + 3;
  FUN_08887480((int)(param_1 + 0xf));
  local_30[0] = param_4;
  FUN_08ad07e0(puVar1);
  FUN_08ad0990(puVar1,1);
  FUN_08ad09bc((int)puVar1,param_5);
  FUN_08ad09f8((int)puVar1,local_30);
  FUN_08ad0900((int)puVar1,param_2);
  param_1[0xe] = param_3;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}

// residual: retail emits the three zero stores +8,+4,+0 (descending); ours emits them lowest-first whatever the source order.
// tried: [2],[1],[0] and [0],[1],[2] source orders (and [1],[2],[0]); GCC keeps its own order for equal-value stores. parked.
// near miss from lane lbp2b (unreviewed)
