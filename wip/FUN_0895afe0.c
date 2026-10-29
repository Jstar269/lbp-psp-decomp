/* LBPMATCH module=EBOOT.BIN start=0x0895afe0 end=0x0895b05c symbol=FUN_0895afe0 lang=c99 */
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
extern int FUN_089593e8(int param_1,int param_2,undefined4 param_3);
extern void FUN_0895a8c4(int param_1);
extern undefined4 FUN_08b8dfd8(char *param_1);
extern void FUN_08b8e050(undefined1 *param_1);
extern undefined4 FUN_08b9ca80(undefined4 param_1);
extern void FUN_0895af50();

void FUN_0895afe0(undefined4 param_1,int param_2)
{
  int iVar1;
  
  if ((DAT_08befb90 == '\0') && (iVar1 = FUN_08b8dfd8((char *)(&DAT_08befb90)), iVar1 != 0)) {
    FUN_0895a8c4((int)((int)&DAT_08befbb0));
    FUN_08b8e050((undefined1 *)(&DAT_08befb90));
    FUN_08b9ca80((undefined4)(FUN_0895af50));
  }
  FUN_089593e8((int)(DAT_08befc04),(int)(param_2),(undefined4)(0x10));
  return;
}

// 7 words differ: local-static guard is signed and register layout differs; reconstruct C++ guarded object.
// near miss from lane lbp5a (unreviewed)
