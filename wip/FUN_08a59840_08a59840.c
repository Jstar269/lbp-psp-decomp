/* LBPMATCH module=EBOOT.BIN start=0x08a59840 end=0x08a598c4 symbol=FUN_08a59840 lang=c99 */
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

extern void FUN_088050b8();
extern void FUN_08a1ef48();

void FUN_08a59840(int *param_1)
{
  int iVar1;
  int *piVar2;
  int *local_20 [4];
  
  iVar1 = (**(code **)(*param_1 + 100))();
  piVar2 = (int *)param_1[0x45];
  param_1[0x45] = 0;
  if (piVar2 != (int *)0x0) {
    FUN_088050b8(piVar2);
  }
  if ((param_1[0x4a] != 0xffff) && (iVar1 != 0)) {
    local_20[0] = (int *)0x0;
    FUN_08a1ef48(iVar1,param_1[0x4a],(int *)local_20);
    if (local_20[0] != (int *)0x0) {
      FUN_088050b8(local_20[0]);
    }
  }
  return;
}

// 2 words left: retail loads the vptr into v1 (`lw v1,0(a0); lw v0,100(v1)`) where every
// form tried here coalesces it into v0. Tried: the generated expression, a named `vt`/`fn`
// pair, a real C++ virtual call with a 26-slot vtable at offset 100, an opaque void* cast and
// a char* + 100 offset. All 33/33 words with 2 differ at +0x10.
// near miss from lane lbp2b (unreviewed)
