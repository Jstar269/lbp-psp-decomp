/* LBPMATCH module=EBOOT.BIN start=0x0895b05c end=0x0895b0e4 symbol=FUN_0895b05c lang=c99 */
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

extern undefined DAT_08befb90;
extern undefined DAT_08befbb0;
extern undefined4 DAT_08befc04;
extern void FUN_0895945c();
extern void FUN_0895a8c4();
extern undefined4 FUN_08b8dfd8();
extern void FUN_08b8e050();
extern undefined4 FUN_08b9ca80();
extern void FUN_0895af50();

void FUN_0895b05c(undefined4 param_1,int *param_2)
{
  int iVar1;
  
  if (*param_2 != 0) {
    if ((DAT_08befb90 == '\0') && (iVar1 = FUN_08b8dfd8(&DAT_08befb90), iVar1 != 0)) {
      FUN_0895a8c4((int)&DAT_08befbb0);
      FUN_08b8e050(&DAT_08befb90);
      FUN_08b9ca80(FUN_0895af50);
    }
    FUN_0895945c(DAT_08befc04,*param_2);
    *param_2 = 0;
  }
  return;
}

// Primary profile initial candidate: 32 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
