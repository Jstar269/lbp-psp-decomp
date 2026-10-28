/* LBPMATCH module=EBOOT.BIN start=0x088cfc38 end=0x088cfcec symbol=FUN_088cfc38 lang=c99 cc=gcc404xs-Os */
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

extern undefined DAT_088cfc38;
extern undefined * DAT_08beed14;
extern undefined4 DAT_08beee0c;
extern void FUN_088e68a0();
extern undefined4 FUN_088e6e54();
extern void FUN_088ea1f0();
extern void FUN_088f36b8();

void FUN_088cfc38(void)
{
  int iVar1;
  int iVar2;
  
  FUN_088e68a0(DAT_08beee0c,'\0',0x33);
  FUN_088e68a0(DAT_08beee0c,'\0',0x34);
  FUN_088ea1f0(DAT_08beee0c,'\x01',0x2e);
  iVar1 = FUN_088e6e54(DAT_08beee0c,(int)&DAT_088cfc38);
  if (iVar1 == 0) {
    iVar1 = 0;
    if ((*(ushort *)(DAT_08beed14 + 0x254) != 0xffff) &&
       (iVar2 = *(int *)(DAT_08beed14 + 0x150) + (uint)*(ushort *)(DAT_08beed14 + 0x254) * 0x28,
       iVar2 != 0)) {
      iVar1 = *(int *)(iVar2 + 8);
    }
    FUN_088f36b8(DAT_08beee0c,iVar1);
    return;
  }
  return;
}

// best of the profile sweep: cc=gcc404xs-Os, 21 differing words left of 45.
// near miss from lane lbp2c (unreviewed)
