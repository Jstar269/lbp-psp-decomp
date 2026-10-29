/* LBPMATCH module=EBOOT.BIN start=0x0883e928 end=0x0883e9f8 symbol=FUN_0883e928 lang=c++ */
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
extern void FUN_08839be8(...);
extern void FUN_0883e504(...);
extern void FUN_088406cc(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0883e928(int *param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  
  FUN_08839be8((int)param_1,param_2);
  param_1[0x40] = param_3;
  param_1[0x41] = param_4;
  if ((char)param_1[0x37] == '\0') {
    if (param_1[4] == 0) {
      piVar1 = (int *)param_1[0x3b];
      goto LAB_0883e9b4;
    }
    if (param_1[4] != 0xb) {
      puVar2 = (undefined4 *)(*param_1 + (param_1[3] + -1) * 0x1c);
      param_1[3] = param_1[3] + -1;
      FUN_088406cc((int)puVar2,'\0');
      *puVar2 = 0xffffffff;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x3e) = 1;
  }
  piVar1 = (int *)param_1[0x3b];
LAB_0883e9b4:
  *(undefined1 *)(param_1 + 0x37) = 0;
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    param_1[0x3b] = 0;
  }
  FUN_0883e504(param_1,0xb);
  return;
}

// 52 words differ; generated control flow and virtual destructor need structured reconstruction.
// near miss from lane lbp7a (unreviewed)
