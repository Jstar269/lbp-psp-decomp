/* LBPMATCH module=EBOOT.BIN start=0x08a781e0 end=0x08a782a0 symbol=FUN_08a781e0 lang=c99 */
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

extern void FUN_089054dc();
extern void FUN_08909b1c(float, void *, int);
extern float DAT_08bab59c;
extern void FUN_08a1d7d0();
extern void FUN_08a25d40();
extern void FUN_08a5ec40();
extern void FUN_08adc5f8(float, void *, int, int, int, int);
extern void FUN_08adc754();
extern void FUN_08adc81c();
extern void FUN_08adc834();
extern void FUN_08adcbe0();
extern void FUN_08adce90();

typedef struct { char a[596]; uint *ptr; char b[1276]; int *other; } Obj;
void FUN_08a781e0(Obj *obj)
{
  uint *puVar1;
  int iVar2;
  
  int param_1 = (int)obj;
  iVar2 = (int)obj->other;
  puVar1 = obj->ptr;
  FUN_08adc81c(puVar1);
  FUN_08adc5f8(0.0f,puVar1,0,*(undefined4 *)(iVar2 + 4),0,0);
  FUN_08adc754(puVar1,0);
  FUN_08adc834(puVar1);
  FUN_08adcbe0(puVar1,0,0,0,8);
  FUN_08adce90(puVar1);
  FUN_08a1d7d0(*(int **)(param_1 + 0x188));
  FUN_08909b1c(DAT_08bab59c,(int *)(param_1 + 0x66a0),6);
  FUN_08a25d40((undefined1 (*) [64])(param_1 + 400));
  FUN_08a5ec40(param_1);
  FUN_089054dc(param_1 + 0x64b0);
  return;
}

// 10 words differ: s1/s2 allocation and float-load order. Typed object and assignment reordering did not change allocation.
// near miss from lane lbp7a (unreviewed)
