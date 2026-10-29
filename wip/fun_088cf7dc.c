/* LBPMATCH module=EBOOT.BIN start=0x088cf7dc end=0x088cf88c symbol=FUN_088cf7dc lang=c99 cc=gcc404xs-O2 */
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

extern undefined * DAT_08beed14;
extern undefined4 DAT_08beee0c;
extern void FUN_088dd3fc();
extern void FUN_088e68a0();
extern void FUN_088e76dc();
extern void FUN_08a59840();

void FUN_088cf7dc(void)
{
  int iVar1;
  
  FUN_088e68a0(DAT_08beee0c,'\0',0x3a);
  if (((*(ushort *)(DAT_08beed14 + 0x254) != 0xffff) &&
      (iVar1 = *(int *)(DAT_08beed14 + 0x150) + (uint)*(ushort *)(DAT_08beed14 + 0x254) * 0x28,
      iVar1 != 0)) && (*(int **)(iVar1 + 0xc) != (int *)0x0)) {
    FUN_08a59840(*(int **)(iVar1 + 0xc));
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x7c))();
  }
  FUN_088dd3fc(DAT_08beed14,(uint)*(ushort *)(DAT_08beed14 + 0x254),'\x01');
  FUN_088e76dc(DAT_08beee0c,'\x01');
  return;
}

// Baseline generated candidate; 30 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
