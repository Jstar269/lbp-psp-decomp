/* LBPMATCH module=EBOOT.BIN start=0x08840f44 end=0x08840f64 symbol=FUN_08840f44 lang=c99 */
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


void FUN_08840f44(undefined4 *param_1)
{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 1;
  param_1[5] = 0;
  param_1[3] = puVar1;
  *param_1 = 0;
  param_1[1] = puVar1;
  param_1[4] = 0;
  puVar1[1] = puVar1;
  return;

}
// 1 word differs: retail's first store is sw v0,4(v0) (base is the node pointer v0 = a0+4, offset 4); ours folds the address to sw v0,8(a0).
// the other seven words match with the statement order in this file (a permutation search over the store order never produced the v0-based address).
// tried: puVar1[1] store, param_1[2] store, store-order permutations on the param_1[n] form
// near miss from lane lbp3c (unreviewed)
