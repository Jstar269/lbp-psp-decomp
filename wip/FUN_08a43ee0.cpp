/* LBPMATCH module=EBOOT.BIN start=0x08a43ee0 end=0x08a43f7c symbol=FUN_08a43ee0 lang=c++ */
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
extern void FUN_08a43d74(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31(); virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35(); virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39(); virtual void d40(); virtual void d41(); virtual void d42(); virtual int m(); };

extern "C" void FUN_08a43ee0(int *param_1,int *param_2,int param_3)
{
  int iVar1;
  
  iVar1 = ((VC_0 *)(param_2))->m();
  if ((param_2[0x11] == 0x26) ||
     (((param_1[0x95] != 0 && ((*(uint *)(param_1[0x95] + 0x2e0) & 1) != 0)) && (iVar1 != 0)))) {
    FUN_08a43d74(param_1,param_2[0x11] == 0x26);
    *(uint *)(param_3 + 0xac) = *(uint *)(param_3 + 0xac) | 1;
  }
  return;
}


// 10 words differ: virtual dispatch and boolean register scheduling; vtable slot corrected to 0xac.
// near miss from lane lbp5a (unreviewed)
