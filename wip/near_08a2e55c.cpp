/* LBPMATCH module=EBOOT.BIN start=0x08a2e55c end=0x08a2e5c8 symbol=FUN_08a2e55c lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void m(int); };

extern "C" undefined4 FUN_08a2e55c(int *param_1,undefined4 param_2,int *param_3,undefined4 param_4,char param_5)
{
  int iVar1;
  
  if (param_5 != '\0') {
    iVar1 = *param_3;
    *(undefined1 *)(param_1 + 4) = 1;
    param_1[0x2a] = iVar1;
    *param_3 = 0;
    return 1;
  }
  ((VC_0 *)(param_1))->m((int)(param_3));
  param_1[0x2b] = 0;
  return 1;
}

// Primary profile initial candidate: 19 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
