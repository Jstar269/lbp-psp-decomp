/* LBPMATCH module=EBOOT.BIN start=0x089f8014 end=0x089f80c0 symbol=FUN_089f8014 lang=c99 rodata=0x08bc2ba0 */
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

extern undefined * DAT_08be8510;
extern undefined4 DAT_08bf8730;
extern int FUN_08a9dbec();

undefined4 FUN_089f8014(unsigned char param_1,uint param_2)
{
  int local_20;
  int local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (DAT_08bf8730) return 1;
  if (param_1 && DAT_08be8510 && 0.999f <= *(float *)(DAT_08be8510 + 0x47c)) return 1;
  if ((int)param_2 <= 0) return 0;
  FUN_08a9dbec(&local_20, &local_1c, &uStack_18, &uStack_14);
  if ((uint)(local_20 + local_1c) >= param_2) return 0;
  return 1;
}
// 16 differing words: corrected unsigned input and float unordered semantics; remaining mismatch is return-block layout and registers.
// near miss from lane lbp1c (unreviewed)
