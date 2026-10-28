/* LBPMATCH module=EBOOT.BIN start=0x08911afc end=0x08911ba0 symbol=FUN_08911afc lang=c99 cc=gcc171-Os */
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

extern undefined * DAT_08be8480;
extern undefined * DAT_08bf7304;
extern void FUN_08910574();
extern void FUN_0891076c();
extern undefined4 FUN_08a50fbc();
extern void FUN_08ac97c0();
extern int FUN_08ac980c();

void FUN_08911afc(int param_1)
{
  int iVar1;
  
  FUN_0891076c();
  iVar1 = FUN_08ac980c(*(int *)(param_1 + 0x1c));
  if (iVar1 != 0) {
    FUN_08ac97c0(*(undefined4 *)(param_1 + 0x1c));
  }
  FUN_08a50fbc();
  if (DAT_08be8480 == 0) {
    iVar1 = *(int *)(param_1 + 0x18);
LAB_08911b84:
    if (iVar1 == 6) {
      return;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x18);
    if (*(char *)(DAT_08be8480 + 4) == '\0') goto LAB_08911b84;
    if (iVar1 != 4) {
      return;
    }
    iVar1 = 5;
    if (*(char *)(DAT_08bf7304 + 0x6b1) != '\0') goto LAB_08911b74;
  }
  iVar1 = 1;
LAB_08911b74:
  FUN_08910574(DAT_08bf7304 + 0x87c,iVar1);
  return;
}

// profile sweep: 22 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
